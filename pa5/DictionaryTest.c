/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - pa5
 *
 * DictionaryTest.c
 * Test client for the Dictionary ADT - prints out # of vertices of each platonic solid
 *   compile: gcc -o DictionaryTest Dictionary.c DictionaryTest.c
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

  int main(int argc, char* argv[]){
    Dictionary A = newDictionary();
    char* k;
    char* v;
    char* word1[] = {"cube","dodecahedron","icosahedron","octahedron","tetrahedron"};
    char* word2[] = {"eight","twenty","twelve","six","four"};
    int i;

    printf("Is my dictionary empty? %s\n", (isEmpty(A)?"true":"false"));
    printf("Size of Dictionary A: %d\n", size(A));

    for(i=0; i<5; i++){
      insert(A, word1[i], word2[i]);
    }

    printDictionary(stdout, A);

    for(i=0; i<5; i++){
      k = word1[i];
      v = lookup(A, k);
      printf("polyhedron= \"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"vertices="), v);
    }

    //insert(A, "cube", "three"); // error: duplicate keys

    delete(A, "octahedron");
    delete(A, "cube");
   

    printDictionary(stdout, A);

    for(i=0; i<5; i++){
      k = word1[i];
      v = lookup(A, k);
      printf("polyhedron=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"vertices="), v);
    }

    // delete(A, "octahedron");  // error: key not found

    printf("Is my dictionary empty? %s\n", (isEmpty(A)?"true":"false"));
    printf("Size of Dictionary A: %d\n", size(A));
    makeEmpty(A);
    printf("Is my dictionary empty? %s\n", (isEmpty(A)?"true":"false"));

    freeDictionary(&A);

    return(EXIT_SUCCESS);
  }
