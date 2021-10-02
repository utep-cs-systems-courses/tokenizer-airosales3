#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*Return 1 if the character is a space, otherwise return 0
*/
int space_char(char c)
{
  if (c == ' '|| c == '\t'){
    return 1;
  }
  return 0;
}

/*Return 1 if the character is not a space, otherwise retunr 0*/
int non_space_char(char c)
{
  if(c != ' ' || c != '\t')
  {
    return 1;
  }
  return 0;
}

/*Points to the first non-space char in the fist word*/
char *word_start(char *s)
{
  int ptr = 0;
  
  while(space_char(s[ptr]) == 1)
  {
    ptr++;

    if(space_char(s[ptr]) != 1)
      return s++;
  }
  return s;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word))
  {
    word++;

    if(*word == 32)
      return word;
  }
  return "0";
}

int count_words(char *str)
{
  int i = 0;
  int count = 0;

  while(str[i] != '\0')
  {
    if(non_space_char(str[i]) && space_char(str[i+1])
    {
      count++;
    }

    i++;
  }

    return count;
}

  char *copy_str(char *inStr, short len)
  {
    char* copy = NULL;
    char* pointer = inStr;

    copy = (char*)malloc((len+1) * sizeof(char));
    copy[len] = '\0';

    int plc = 0;

    while(*pointer != '\0')
    {
      copy[plc++] = *pointer++;
    }

    return copy;

  }  

  /*Tokenizer Functions*/
  char **tokenizer(char* str)
  {
    int size = count_words(str);
    char **tokens = (char**)malloc((size + 1) * sizeof(char*));

    char* start = str;
    char* end = word_terminaotr(str);

    int i = 0;
    for(i = 0; i < size; i++)
    {
      if(i > 0)
	{
	  start = word_start(end);
	  end = word_terminator(start);
	}
      int word_size = end - start;
      tokens[i] = malloc(word_size * sizeof(char));

      for (int j = 0; j < word_size; j++)
	{
	  tokens[i][j] = start[j];
	}
      tokens[i] = 0;
      return tokens;
    }

    void print_tokens(char **token)
    {
      int i;
      for(i = 0; tokens[i] != NULL; i++)
	{
	  printf("Token [%d]: %s\n", i, tokens[i]);
	}
    }

    void free_tokens(char **tokens)
    {
      int i;
      for(i = 0; tokens[i] != NULL; i++)
	{
	  free(tokens[i]);
	}
      free(tokens);

    }
    }
  
