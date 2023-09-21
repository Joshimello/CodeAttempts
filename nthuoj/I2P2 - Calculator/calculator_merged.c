#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// for lex
#define MAXLEN 256

// Token types
typedef enum {
    INT, ID, ASSIGN, LPAREN, RPAREN, END, ENDFILE, ADDSUB, MULDIV, INCDEC, AND, OR, XOR, ADDSUB_ASSIGN, UNKNOWN
} TokenSet;

TokenSet getToken(void);
TokenSet curToken = UNKNOWN;
char lexeme[MAXLEN];

// Test if a token matches the current token
int match(TokenSet token);
// Get the next token
void advance(void);
// Get the lexeme of the current token
char *getLexeme(void);


// for parser
#define TBLSIZE 64
// Set PRINTERR to 1 to print error message while calling error()
// Make sure you set PRINTERR to 0 before you submit your code
#define PRINTERR 1

// Call this macro to print error message and exit the program
// This will also print where you called it in your program
#define error(errorNum) { \
    if (PRINTERR) \
        fprintf(stderr, "error() called at %s:%d: ", __FILE__, __LINE__); \
    err(errorNum); \
}

// Error types
typedef enum {
    UNDEFINED, MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NOTLVAL, DIVZERO, SYNTAXERR
} ErrorType;

// Structure of the symbol table
typedef struct {
    int val;
    char name[MAXLEN];
} Symbol;

// Structure of a tree node
typedef struct _Node {
    TokenSet data;
    int val;
    char lexeme[MAXLEN];
    struct _Node *left;
    struct _Node *right;
} BTNode;

int sbcount = 0;
Symbol table[TBLSIZE];

// Initialize the symbol table with builtin variables
void initTable(void);
// Get the value of a variable
int getval(char *str);
// Set the value of a variable
int setval(char *str, int val);
// Make a new node according to token type and lexeme
BTNode *makeNode(TokenSet tok, const char *lexe);
// Free the syntax tree
void freeTree(BTNode *root);
BTNode *term(void);
BTNode *term_tail(BTNode *left);
BTNode *expr(void);
BTNode *expr_tail(BTNode *left);

BTNode *assign_expr(void);
BTNode *or_expr(void);
BTNode *or_expr_tail(BTNode *left);
BTNode *xor_expr(void);
BTNode *xor_expr_tail(BTNode *left);
BTNode *and_expr(void);
BTNode *and_expr_tail(BTNode *left);
BTNode *addsub_expr(void);
BTNode *addsub_expr_tail(BTNode *left);
BTNode *muldiv_expr(void);
BTNode *muldiv_expr_tail(BTNode *left);
BTNode *unary_expr(void);
BTNode *factor(void);

void statement(void);
// Print error message and exit the program
void err(ErrorType errorNum);


// for codeGen
// Evaluate the syntax tree
int evaluateTree(BTNode *root);
// Print the syntax tree in prefix
void printPrefix(BTNode *root);


/*============================================================================================
lex implementation
============================================================================================*/

TokenSet getToken(void)
{
    int i = 0;
    char c = '\0';

    while ((c = fgetc(stdin)) == ' ' || c == '\t');

    if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i < MAXLEN) {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    } else if (c == '+' || c == '-') {
        char t = fgetc(stdin);
        if(t == '='){
            lexeme[0] = c;
            lexeme[1] = '=';
            lexeme[2] = '\0';
            return ADDSUB_ASSIGN;
        } else if(c == '+' && t == '+'){
            lexeme[0] = '+';
            lexeme[1] = '+';
            lexeme[2] = '\0';
            return INCDEC;
        } else if(c == '-' && t == '-'){
            lexeme[0] = '-';
            lexeme[1] = '-';
            lexeme[2] = '\0';
            return INCDEC;
        } else {
            ungetc(t, stdin);
            lexeme[0] = c;
            lexeme[1] = '\0';
            return ADDSUB;
        }
    } else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    } else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    } else if (c == '=') {
        strcpy(lexeme, "=");
        return ASSIGN;
    } else if (c == '(') {
        strcpy(lexeme, "(");
        return LPAREN;
    } else if (c == ')') {
        strcpy(lexeme, ")");
        return RPAREN;
    } else if (c == '&') {
        strcpy(lexeme, "&");
        return AND;
    } else if (c == '|') {
        strcpy(lexeme, "|");
        return OR;
    } else if (c == '^') {
        strcpy(lexeme, "^");
        return XOR;
    } else if (isalpha(c) || c == '_') {
        
        lexeme[0] = c;

        char t = fgetc(stdin); int j = 1;
        while(isalpha(t) || t == '_' || isdigit(t)){
            lexeme[j] = t;
            j++;
            t = fgetc(stdin);
        }
        ungetc(t, stdin);
        lexeme[j] = '\0';

        return ID;
    } else if (c == EOF) {
        return ENDFILE;
    } else {
        return UNKNOWN;
    }
}

void advance(void) {
    curToken = getToken();
}

int match(TokenSet token) {
    if (curToken == UNKNOWN)
        advance();
    return token == curToken;
}

char *getLexeme(void) {
    return lexeme;
}


/*============================================================================================
parser implementation
============================================================================================*/

void initTable(void) {
    strcpy(table[0].name, "x");
    table[0].val = 0;
    strcpy(table[1].name, "y");
    table[1].val = 0;
    strcpy(table[2].name, "z");
    table[2].val = 0;
    sbcount = 3;
}

int getval(char *str) {
    int i = 0;

    for (i = 0; i < sbcount; i++)
        if (strcmp(str, table[i].name) == 0)
            return table[i].val;

    if (sbcount >= TBLSIZE){
        error(RUNOUT);
    }

    strcpy(table[sbcount].name, str);
    table[sbcount].val = 0;
    sbcount++;
    return 0;
}

int setval(char *str, int val) {
    int i = 0;

    for (i = 0; i < sbcount; i++) {
        if (strcmp(str, table[i].name) == 0) {
            table[i].val = val;
            return val;
        }
    }

    if (sbcount >= TBLSIZE){
        error(RUNOUT);
    }

    strcpy(table[sbcount].name, str);
    table[sbcount].val = val;
    sbcount++;
    return val;
}

BTNode *makeNode(TokenSet tok, const char *lexe) {
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    strcpy(node->lexeme, lexe);
    node->data = tok;
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeTree(BTNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

BTNode *assign_expr(void) {
    BTNode *res, *left;
    res = or_expr();
    if(res->data == ID) {
        if(match(ASSIGN)) {
            left = res;
            res = makeNode(ASSIGN, getLexeme());
            advance();
            res->left = left;
            res->right = assign_expr();
        } else if(match(ADDSUB_ASSIGN)) {
            left = res;
            res = makeNode(ADDSUB_ASSIGN, getLexeme());
            advance();
            res->left = left;
            res->right = assign_expr();
        // }
        } else if(match(LPAREN) || match(ID) || match(INCDEC)) {
            error(SYNTAXERR);
        }
    }
    return res;
}

BTNode *or_expr(void){
    BTNode *retp = xor_expr();
    return or_expr_tail(retp);
}
BTNode *or_expr_tail(BTNode *left){
    BTNode *retp = NULL;
    if(match(OR)){
        retp = makeNode(OR, getLexeme());
        advance();
        retp->left = left;
        retp->right = xor_expr();
        return or_expr_tail(retp);
    } else {
        return left;
    }
}
BTNode *xor_expr(void){
    BTNode *retp = and_expr();
    return xor_expr_tail(retp);
}
BTNode *xor_expr_tail(BTNode *left){
    BTNode *retp = NULL;
    if(match(XOR)){
        retp = makeNode(XOR, getLexeme());
        advance();
        retp->left = left;
        retp->right = and_expr();
        return xor_expr_tail(retp);
    } else {
        return left;
    }
}
BTNode *and_expr(void){
    BTNode *retp = addsub_expr();
    return and_expr_tail(retp);
}
BTNode *and_expr_tail(BTNode *left){
    BTNode *retp = NULL;
    if(match(AND)){
        retp = makeNode(AND, getLexeme());
        advance();
        retp->left = left;
        retp->right = addsub_expr();
        return and_expr_tail(retp);
    } else {
        return left;
    }
}
BTNode *addsub_expr(void){
    BTNode *retp = muldiv_expr();
    return addsub_expr_tail(retp);
}
BTNode *addsub_expr_tail(BTNode *left){
    BTNode *retp = NULL;
    if(match(ADDSUB)){
        retp = makeNode(ADDSUB, getLexeme());
        advance();
        retp->left = left;
        retp->right = muldiv_expr();
        return addsub_expr_tail(retp);
    } else {
        return left;
    }
}
BTNode *muldiv_expr(void){
    BTNode *retp = unary_expr();
    return muldiv_expr_tail(retp);
}
BTNode *muldiv_expr_tail(BTNode *left){
    BTNode *retp = NULL;
    if(match(MULDIV)){
        retp = makeNode(MULDIV, getLexeme());
        advance();
        retp->left = left;
        retp->right = unary_expr();
        return muldiv_expr_tail(retp);
    } else {
        return left;
    }
}
BTNode *unary_expr(void){
    BTNode *retp;
    if(match(ADDSUB)){
        retp = makeNode(ADDSUB, getLexeme());
        advance();
        retp->left = makeNode(INT, "0");
        retp->right = unary_expr();
    }
    else{
        retp = factor();
    }
    return retp;
}


// factor := INT | ADDSUB INT |
//		   	 ID  | ADDSUB ID  |
//		   	 ID ASSIGN expr |
//		   	 LPAREN expr RPAREN |
//		   	 ADDSUB LPAREN expr RPAREN
BTNode *factor(void) {
    BTNode *retp = NULL, *left = NULL;

    if (match(INT)) {
        retp = makeNode(INT, getLexeme());
        advance();
    }

    else if (match(ID)) {
        left = makeNode(ID, getLexeme());
        advance();
        retp = left;

        // if (!match(ASSIGN)) {
        //     retp = left;
        // } else {
        //     retp = makeNode(ASSIGN, getLexeme());
        //     advance();
        //     retp->left = left;
        //     retp->right = expr();
        // }
    }

    else if (match(INCDEC)){
        retp = makeNode(INCDEC, getLexeme());
        advance();
        if(match(ID)){
            retp->left = makeNode(ID, getLexeme());
            advance();
            retp->right = makeNode(INT, "1");
        } else {
            printf("EXIT 1\n");
            exit(0);
        }
    }

    // else if (match(ADDSUB)) {
    //     retp = makeNode(ADDSUB, getLexeme());
    //     retp->left = makeNode(INT, "0");
    //     advance();
    //     if (match(INT)) {
    //         retp->right = makeNode(INT, getLexeme());
    //         advance();
    //     } else if (match(ID)) {
    //         retp->right = makeNode(ID, getLexeme());
    //         advance();
    //     } else if (match(LPAREN)) {
    //         advance();
    //         retp->right = expr();
    //         if (match(RPAREN))
    //             advance();
    //         else
    //             error(MISPAREN);
    //     } else {
    //         error(NOTNUMID);
    //     }
    // }

    else if (match(LPAREN)) {
        advance();
        retp = assign_expr();
        if (match(RPAREN))
            advance();
        else {
            printf("EXIT 1\n");
            error(MISPAREN);
        }
    } else {
        printf("EXIT 1\n");
        error(NOTNUMID);
    }
    return retp;
}

// term := factor term_tail
// BTNode *term(void) {
//     BTNode *node = factor();
//     return term_tail(node);
// }

// // term_tail := MULDIV factor term_tail | NiL
// BTNode *term_tail(BTNode *left) {
//     BTNode *node = NULL;

//     if (match(MULDIV)) {
//         node = makeNode(MULDIV, getLexeme());
//         advance();
//         node->left = left;
//         node->right = factor();
//         return term_tail(node);
//     } else {
//         return left;
//     }
// }

// // expr := term expr_tail
// BTNode *expr(void) {
//     BTNode *node = term();
//     return expr_tail(node);
// }

// // expr_tail := ADDSUB term expr_tail | NiL
// BTNode *expr_tail(BTNode *left) {
//     BTNode *node = NULL;

//     if (match(ADDSUB)) {
//         node = makeNode(ADDSUB, getLexeme());
//         advance();
//         node->left = left;
//         node->right = term();
//         return expr_tail(node);
//     } else {
//         return left;
//     }
// }

int reg[8];

// statement := ENDFILE | END | expr END
void statement(void) {
    BTNode *retp = NULL;

    if (match(ENDFILE)) {
        printf("MOV r0 [0]\nMOV r1 [4]\nMOV r2 [8]\nEXIT 0\n");
        exit(0);
    } else if (match(END)) {
        // printf(">> ");
        advance();
    } else {
        retp = assign_expr();
        if (match(END)) {
            for(int i = 0; i < 8; i++) reg[i] = 1;
            evaluateTree(retp);
            // printf("%d\n", evaluateTree(retp));
            // printf("Prefix traversal: ");
            // printPrefix(retp);
            // printf("\n");
            freeTree(retp);
            // printf(">> ");
            advance();
        } else {
            printf("EXIT 1\n");
            error(SYNTAXERR);
        }
    }
}

void err(ErrorType errorNum) {
    if (PRINTERR) {
        fprintf(stderr, "error: ");
        switch (errorNum) {
            case MISPAREN:
                fprintf(stderr, "mismatched parenthesis\n");
                break;
            case NOTNUMID:
                fprintf(stderr, "number or identifier expected\n");
                break;
            case NOTFOUND:
                fprintf(stderr, "variable not defined\n");
                break;
            case RUNOUT:
                fprintf(stderr, "out of memory\n");
                break;
            case NOTLVAL:
                fprintf(stderr, "lvalue required as an operand\n");
                break;
            case DIVZERO:
                fprintf(stderr, "divide by constant zero\n");
                break;
            case SYNTAXERR:
                fprintf(stderr, "syntax error\n");
                break;
            default:
                fprintf(stderr, "undefined error\n");
                break;
        }
    }
    exit(0);
}


/*============================================================================================
codeGen implementation
============================================================================================*/

int adr(char str[]){
    for(int i = 0; i < sbcount; i++){
        if(!strcmp(str, table[i].name)) return i;
    }

    if (sbcount >= TBLSIZE)
        error(RUNOUT);

    strcpy(table[sbcount].name, str);
    table[sbcount].val = 0;
    return sbcount++;
}

int evaluateTree(BTNode *root) {
    int retval = 0, lv = 0, rv = 0;

    if (root != NULL) {
        int r;
        switch (root->data) {
            case ID:
                for(int i = 0; i < 8; i++){
                    if(reg[i]){
                         r = i;
                         break;
                    }
                }
                reg[r] = 0;
                printf("MOV r%d [%d]\n", r, adr(root->lexeme) * 4);
                return r;
                // retval = getval(root->lexeme);
                break;
            case INT:
                for(int i = 0; i < 8; i++){
                    if(reg[i]){
                        r = i;
                        break;
                    }
                }
                reg[r] = 0;
                printf("MOV r%d %d\n", r, atoi(root->lexeme));
                return r;
                // retval = atoi(root->lexeme);
                break;
            case ASSIGN:
                rv = evaluateTree(root->right);
                printf("MOV [%d] r%d\n", adr(root->left->lexeme) * 4, rv);
                // retval = setval(root->left->lexeme, rv);
                break;

            case ADDSUB:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);
                if (strcmp(root->lexeme, "+") == 0) {
                    printf("ADD r%d r%d\n", lv, rv);
                    reg[rv] = 1;
                    return lv;
                    // retval = lv + rv;
                } else if (strcmp(root->lexeme, "-") == 0) {
                    printf("SUB r%d r%d\n", lv, rv);
                    reg[rv] = 1;
                    return lv;
                    // retval = lv - rv;
                }
                break;
            case MULDIV:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);
                if (strcmp(root->lexeme, "*") == 0) {
                    printf("MUL r%d r%d\n", lv, rv);
                    reg[rv] = 1;
                    return lv;
                    // retval = lv * rv;
                } else if (strcmp(root->lexeme, "/") == 0) {
                    if (rv == 0){
                        error(DIVZERO);
                    }
                    printf("DIV r%d r%d\n", lv, rv);
                    reg[rv] = 1;
                    return lv;
                    // retval = lv / rv;
                }
                break;
            case AND:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);

                printf("AND r%d r%d\n", lv, rv);
                reg[rv] = 1;
                return lv;
                
                break;
            case OR:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);

                printf("OR r%d r%d\n", lv, rv);
                reg[rv] = 1;
                return lv;

                break;
            case XOR:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);

                printf("XOR r%d r%d\n", lv, rv);
                reg[rv] = 1;
                return lv;

                break;
            case INCDEC:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);

                if(!strcmp(root->lexeme, "++")){

                    for(int i = 0; i < 8; i++){
                        if(reg[i]){
                            r = i;
                            break;
                        }
                    }
                    reg[r] = 0;

                    printf("ADD r%d r%d\n", lv, rv);
                    printf("MOV [%d] r%d\n", adr(root->left->lexeme) * 4, lv);
                    reg[rv] = 1;

                    return lv;

                } else if(!strcmp(root->lexeme, "--")){

                    for(int i = 0; i < 8; i++){
                        if(reg[i]){
                            r = i;
                            break;
                        }
                    }
                    reg[r] = 0;

                    printf("SUB r%d r%d\n", lv, rv);
                    printf("MOV [%d] r%d\n", adr(root->left->lexeme) * 4, lv);
                    reg[rv] = 1;

                    return lv;

                }

                break;
            case ADDSUB_ASSIGN:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);

                if(!strcmp(root->lexeme, "+=")){

                    printf("ADD r%d r%d\n", lv, rv);
                    printf("MOV [%d] r%d\n", adr(root->left->lexeme) * 4, lv);
                    reg[lv] = 1;

                    return rv;

                } else if(!strcmp(root->lexeme, "-=")){

                    printf("SUB r%d r%d\n", lv, rv);
                    printf("MOV [%d] r%d\n", adr(root->left->lexeme) * 4, lv);
                    reg[lv] = 1;

                    return rv;

                }

                break;
            default:
                retval = 0;
        }
    }
    return 0;
}

void printPrefix(BTNode *root) {
    if (root != NULL) {
        printf("%s ", root->lexeme);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}


/*============================================================================================
main
============================================================================================*/

// This package is a calculator
// It works like a Python interpretor
// Example:
// >> y = 2
// >> z = 2
// >> x = 3 * y + 4 / (2 * z)
// It will print the answer of every line
// You should turn it into an expression compiler
// And print the assembly code according to the input

// This is the grammar used in this package
// You can modify it according to the spec and the slide
// statement  :=  ENDFILE | END | expr END
// expr    	  :=  term expr_tail
// expr_tail  :=  ADDSUB term expr_tail | NiL
// term 	  :=  factor term_tail
// term_tail  :=  MULDIV factor term_tail| NiL
// factor	  :=  INT | ADDSUB INT |
//		   	      ID  | ADDSUB ID  |
//		   	      ID ASSIGN expr |
//		   	      LPAREN expr RPAREN |
//		   	      ADDSUB LPAREN expr RPAREN

int main() {
    initTable();
    // printf(">> ");
    while (1) {
        statement();
    }
    return 0;
}
