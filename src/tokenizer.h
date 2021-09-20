#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c == ' ' || c == '\t')
  {
    return 1;
  }

  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if(c == ' ' || c == '\t')
  {
    return 0;
  }

  return 1;

}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  if(count_words(str)>0) //check if there are more than 0 words
  {
    int ptr = 0;  //Initalize the pointer
    if(space_char(str[ptr]))//Checks if the word starts on a whitepsace
      str++;

    while(space_char(str[ptr]))
    {
      ptr++;
    }

    return (str++); //Returns the pointer for the next word
  }

  return str; //Return original array if no valid char exists

}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while(non_space_char(str))
  {
    str++;
    if(str == 32) //Set to 32 as it means that it does not point to anything
      return str; //Return the end of the word
  }

  return "0";

}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while(str[i] != '\0')
    {
      if(non_space_char(str[i]) && space_char(str[i+1]))
      {
	count++;
	i++;
    }

    count += 1;

    if (space_char(str[i-2]))
      count--;

    return count;

  }


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
    char *copy_str(char *inStr, short len)
    {
      int plc = 0;
      char* copy = (char*)malloc(len+1* sizeof(char));
      
      while(plc < len)
      {
	copy[plc] = inStr[plc];
	  plc++;
      }

      return copy;
    }


    /* Helper method to copy_str
     */
    int string_length(char*str)
    {
      int num_chars = 0;
      int pos = 0;

      while(str[pos])
      {
	num_chars++;
	pos++;
      }

      return num_chars;
    }

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
