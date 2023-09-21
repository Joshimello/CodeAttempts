#include "function.h"

Str::Str(char *s){
  head = new Char(s[0]);

  Char *temp = head;
  temp->next = NULL;
  for(int i = 1; s[i]; i++){
    temp = temp->next;
    temp = new Char(s[i]);
  }
  temp->next = NULL;
d
  tail = temp;
}

Str::Str(const Str &s){
  *this = s;
}

Str& Str::strInsert(const Str &s){
  Str *tmp = new Str(s);
  return *tmp;
}