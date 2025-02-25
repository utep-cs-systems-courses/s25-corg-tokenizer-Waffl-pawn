#include <stdio.h>
#include <stdlib.h>
#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c == ' ' || c == '\t'){
    return 0;
  }  
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){

  while(*str != '\0'){
    if(non_space_char(*str) == 1){
      return str;
    }
    str++;
  }
  return NULL;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  while(*str != '\0' && str == NULL){
    str = token_start(str);
    str = token_terminator(str);
    count++;
    str++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newStr = (char *)malloc((len + 1)*sizeof(char));

  for (int i = 0; i < len; i++) {
    *(newStr+i) = *inStr+i;
  }

  *(newStr+(len)) = '\0';

  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  char *start = token_start(str);
  char *end = token_terminator(str);
  char **tokens;
 
  for(int i = 0; i < str_length){
    int length = start - end;
    int temp_cpy = copy_str(start,length);

    tokens[i] = temp_cpy;

    start = token_start(end);
    end = token_terminator(start);
  }
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
