/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - lab4 - 10/28/16
 *
 * CharType.c
 * extracts characters in the input file and places them
 * in the output file
 * compile:  % make 
 *           % CharType <input_file> <output_file>:
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_LENGTH 100

// prototype of function extract_chars 
void extract_chars(char* s, char* a, char* d, char* p, char* w);

  // function main which reads command line arguments 
  int main(int argc, char * argv[]) {
    FILE* in;                                         // handle for input file                             
    FILE* out;                                        // handle for output file
    char* line;                                       // dynamically allocated string holding words in each line
    char* alpha;                                      // dynamically allocated string holding letters
    char* digits;                                     // dynamically allocated string holding numbers
    char* punct;                                      // dyanmically allocated string holding punctuation char
    char* whitspc;                                    // dynamically allocated string holding white spaces
    int counter = 1;                                  // counter for the line number

    // check command line for correct number of arguments 
    if(argc != 3) {
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    // open input file for reading 
    in = fopen(argv[1], "r");
    if( in == NULL) {
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    // open output file for writing 
    out = fopen(argv[2], "w");
    if(out == NULL) {
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
    }

    // allocate strings word and capsWord from heap memory 
    line = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
    alpha = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
    digits = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
    punct = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
    whitspc = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
    assert(line != NULL && alpha != NULL && digits != NULL && punct != NULL && whitspc != NULL);

    // read each word in input file, extract characters 
    while(fgets(line, MAX_STRING_LENGTH, in ) != NULL) {
      extract_chars(line, alpha, digits, punct, whitspc);
      fprintf(out, "line %d contains: \n", counter);

      //if line contains characters
      if(strlen(line) >= 1) {

        //checks if plural amount of characters or singular. ex: 1 character or 6 characters.
        //also prints out how many of each character was found & the character string into output file	
        if(strlen(alpha) <= 1) {
          fprintf(out, "%d alphabetic character: %s\n", (int) strlen(alpha), alpha);
          fprintf(out, "%d numeric characters: %s\n", (int) strlen(digits), digits);
          fprintf(out, "%d punctuation characters: %s\n", (int) strlen(punct), punct);
          fprintf(out, "%d whitespace characters: %s\n", (int) strlen(whitspc), whitspc);
        } 
        else if(strlen(digits) <= 1) {
          fprintf(out, "%d alphabetic characters: %s\n", (int) strlen(alpha), alpha);
          fprintf(out, "%d numeric character: %s\n", (int) strlen(digits), digits);
          fprintf(out, "%d punctuation characters: %s\n", (int) strlen(punct), punct);
          fprintf(out, "%d whitespace characters: %s\n", (int) strlen(whitspc), whitspc);
        } 
        else if(strlen(punct) <= 1) {
          fprintf(out, "%d alphabetic characters: %s\n", (int) strlen(alpha), alpha);
          fprintf(out, "%d numeric characters: %s\n", (int) strlen(digits), digits);
          fprintf(out, "%d punctuation character: %s\n", (int) strlen(punct), punct);
          fprintf(out, "%d whitespace characters: %s\n", (int) strlen(whitspc), whitspc);
        } 
        else if(strlen(whitspc) <= 1) {
          fprintf(out, "%d alphabetic characters: %s\n", (int) strlen(alpha), alpha);
          fprintf(out, "%d numeric characters: %s\n", (int) strlen(digits), digits);
          fprintf(out, "%d punctuation characters: %s\n", (int) strlen(punct), punct);
          fprintf(out, "%d whitespace character: %s\n", (int) strlen(whitspc), whitspc);
        }
        else {
          fprintf(out, "%d alphabetic characters: %s\n", (int) strlen(alpha), alpha);
          fprintf(out, "%d numeric characters: %s\n", (int) strlen(digits), digits);
          fprintf(out, "%d punctuation characters: %s\n", (int) strlen(punct), punct);
          fprintf(out, "%d whitespace characters: %s\n", (int) strlen(whitspc), whitspc);
        }
        counter++; //move to next line
      }
    }

    // free heap memory associated with string variables 
    free(line);
    free(alpha);
    free(digits);
    free(punct);
    free(whitspc);

    // close input and output files 
    fclose( in );
    fclose(out);

    return EXIT_SUCCESS;
  }

    void extract_chars(char* s, char* a, char* d, char* p, char* w) {
      int i = 0, j = 0, k = 0, l = 0, m = 0;

      while (s[i] != '\0' && i < MAX_STRING_LENGTH) {
        if (isalpha(s[i])) {                            //when character is a letter store it in character array a
          a[j] = s[i];
          j++;
        }
        else if(isdigit(s[i])){                         //when character is a number store it in d
          d[k] = s[i];
          k++;
        }
        else if(ispunct(s[i])){                       //when character is a punctuation character store it in p
          p[l] = s[i];
          l++;
        } 
        else if(isspace(s[i])){                       //when character is a white space character store it in w
          w[m] = s[i];
          m++;
        }
        i++;
      }
      a[j] = '\0';
      d[k] = '\0';
      p[l] = '\0';
      w[m] = '\0';
    }
