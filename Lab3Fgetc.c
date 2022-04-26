/*
  Jason Rodgers
  CPSC 2311 Sp22 Section 01
  jtrodge@g.clemson.edu
*/

#include "Lab3Fgetc.h"

/*Parameter: in is the file pointer that should have been opened in the driver.
 *Return: void
 *Description:
 *This function will use the 'C' style function fgetc to read in characters,
 *one at a time, from the input file. As you read in the characters from the
 *file, check each to determine if you are at the beginning of a comment.
 *If you are at the beginning of a comment call the function rcomment
 *(read comment). If you are not then use the 'C' function putchar to print the
 *chararacter to stdout (standard out, a.k.a. the terminal). */
void start(FILE* in) {
  char a;
  // Read in everything from input file
  // Read file until comment is reached
  while ((a = fgetc(in)) != EOF) {
    // Read file until comment is reached
    if (a == '/') {
      rcomment(in);
    }
    //Not a comment at all
    else {
      putchar(a);
    }
  }
}

/*Parameter:
 *'in' is the file pointer that should have been opened in the driver.
 *Return: void
 *Description:
 *This function is called if you have determined you are at the beginning of a
 *of a comment. It is called by the function start.
 *Now determine the type of comment. Continue to read until
 *you are at the end of the comment.  There are two types of comments. If you
 *determine the comment is of type // then call skipS_comment (skip single line
 *comment) otherwise call skipM_comment (skip multi-line comment) */
void rcomment(FILE* in) {
  char b;
  //Read the next character to determine if single or multi line comment
  //Single line Comment
  if ((b = fgetc(in)) == '/') {
    skipS_comment(in);
  }
  //Multi line comment
  else if (b == '*') {
    skipM_comment(in);
  }
  //Neither a single or multi line comment
  else {
    putchar(b);
  }
}

/*Parameter:
 *'in' is the file pointer that should have been opened in the driver.
 *Return: void
 *Description:
 *This function continues to read and discard everything in a multi-line
 *comment. You are required to use fgetc to read the characters in the
 *comment.*/
void skipM_comment(FILE* in) {
  char a, b;
  // Traversing through the contents of the comments
  while ((a = fgetc(in)) != EOF) {
    //Deletes the end characters of the multi line comment
    if (a == '*') {
      b = fgetc(in);
      if (b == '/') {
        return;
      }
    }
  }
}

/*Parameter:
 *'in' is the file pointer that should have been opened in the driver.
 *Return: void
 *Description:
 *This function continues to read and discard everything in a single-line
 *comment. You are required to use fgetc to read the characters in the
 *comment.*/
void skipS_comment(FILE* in) {
  char a;
  // Traverses through contents of the character
  while ((a = fgetc(in)) != EOF) {
    //Stops traversing until new line is found
    if (a == '\n') {
      return;
    }
  }
}
