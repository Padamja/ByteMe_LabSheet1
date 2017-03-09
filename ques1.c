#include<stdio.h>
#include<string.h>

#define NO_OF_CHARS 256
 
int nextState(char *pattern, int M, int state, int x)
{
  
  // Start from the largest possible value and stop when you find
  // a prefix which is also suffix
  // Code for this function is yet to be written.
 
  return 0;
}
 
/* This builds the transition table which represents Finite Automata for a
  given pattern */
void computeTF(char *pattern, int M, int TF[][NO_OF_CHARS])
{
  int state, x;
  for (state = 0; state <= M; ++state)
  for (x = 0; x < NO_OF_CHARS; ++x)
  TF[state][x] = nextState(pattern, M, state, x);
}
 
/* Prints all occurrences of pattern in txt */
void search(char *pattern, char *txt)
{
  int M = strlen(pattern);
  int N = strlen(txt);
 
  int TF[M+1][NO_OF_CHARS];
 
  computeTF(pattern, M, TF);
 
  // Code to process the string over Finite Automata yet to be written .
  
}
 

int main()
{
  char *txt = "ACDDABCDACDAACDDAB";
  char *pattern = "ACD";
  search(pattern, txt);
  return 0;
}
