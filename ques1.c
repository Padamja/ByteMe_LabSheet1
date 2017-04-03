#include<stdio.h>
#include<string.h>

#define NO_OF_CHARS 256
 
int nextState(char *pattern, int M, int state, int x)
{
  
 // If the character c is same as next character in pattern,
  // then simply increment state
  if (state < M && x == pattern[state])
  return state+1;
 
  int ns, i; // ns stores the result which is next state
 
  // ns finally contains the longest prefix which is also suffix
  // in "pattern[0..state-1]c"
 
  // Start from the largest possible value and stop when you find
  // a prefix which is also suffix
  for (ns = state; ns > 0; ns--)
  {
  if(pattern[ns-1] == x)
  {
  for(i = 0; i < ns-1; i++)
  {
    if (pattern[i] != pattern[state-ns+1+i])
  break;
  }
  if (i == ns-1)
  return ns;
  }
  }
 
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
 
  int i, state=0;
  for (i = 0; i < N; i++)
  {
  state = TF[state][txt[i]];
  if (state == M)
  {
  printf ("\n Pattern found at index %d", i-M+1);
  }
  }
  
}
 

int main()
{
  char *txt = "ACDDABCDACDAACDDAB";
  char *pattern = "ACD";
  search(pattern, txt);
  return 0;
}
