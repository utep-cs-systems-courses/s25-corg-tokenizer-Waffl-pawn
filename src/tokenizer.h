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
char **tokenize(char* str) {
  int num_tokens = count_tokens(str);
  char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));

  int i = 0;
  char *start = token_start(str);

  while (i < num_tokens) {
    char *end = token_terminator(start);
    int length = end - start;

    tokens[i] = copy_str(start, length);

    i++;
    start = token_start(end);
  }

  tokens[i] = '\0';
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  
  while(*tokens[i] != '\0'){
    printf("tokens[%d] = \"%s\"\n", i,tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {  
  while (**tokens != '\0') {
    free(*tokens);
    tokens++;
  }
}
#endif
