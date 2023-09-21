#include "function.h"

class Constant:Public Function{
    
}

Function* Function::parse(stringstream &ss){
    string s;
    ss >> s;
    if(s == "+" || s == "-" || s == "*" || s == "/"){
        Function *a = parse(ss), *b = parse(ss);
        Function *now = Arithmetic::create(a, s[0], b);
        return now;
    }else if(s[0] == 'x'){
        Function *now = Variable::create(s);
        return now;
    }else if(s == "**"){
        Function *a = parse(ss), *b = parse(ss);
        Function *now = Polynomial::create(a, b);
        return now;
    }else if(s == "sin"){
        Function *a = parse(ss);
        Function *now = Sin::create(a);
        return now;
    }else if(s == "cos"){
        Function *a = parse(ss);
        Function *now = Cos::create(a);
        return now;
    }else{
        Function *now = Constant::create(atoi(s.c_str()));
        return now;
    }
}