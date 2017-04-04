/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS 12B - lab3 - 10/21/16
 * 
 * FileReverse.c 
 * same as FileReverse.java
 * compile: % make
 * 	    % FileReverse <input_file> <output_file>
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function prototype
void stringReverse(char* s);


  void stringReverse(char* s){
    int i, j;
    int temp;

    for(i = 0, j = strlen(s)-1; i<=j; i++, j--){
      temp = s[i];
      s[i] = s[j];                    
      s[j] = temp;
    }
  }

  int main(int argc, char* argv[]){
    FILE* in;
    FILE* out;                      
    char word[256];                 
                                        
    if(argc != 3){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    // open input file for reading
    in = fopen(argv[1], "r");

    if( in==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    // open output file for writing
    out = fopen(argv[2], "w");

    if( out==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
    }

    // read words from input file, print on separate lines to output file
    while( fscanf(in, " %s", word) != EOF ){
      stringReverse(word);
      fprintf(out, "%s\n", word);
    }

    // close input and output files
    fclose(in);
    fclose(out);


    return(EXIT_SUCCESS);
  }
