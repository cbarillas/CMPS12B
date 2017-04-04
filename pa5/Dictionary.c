/*
 *
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - pa5
 *
 * Dictionary.c - implements a Dictionary using a hashtable
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Dictionary.h"

const int tableSize = 101;
int hash(char* key);

// private types and functions-------------------------

  // NodeObj
  typedef struct NodeObj {
    char* key;
    char* value;
    struct NodeObj* next;
  } NodeObj;

  // Node
  typedef NodeObj* Node;

  // newNode()
  // constructor for the node type
  Node newNode(char* k, char* v) {
    Node N = malloc(sizeof(Node));
    assert(N != NULL);
    N->key = k;
    N->value = v;
    N->next = NULL;
    return N;
  }

  // freeNode()
  // destructor for Node type
  void freeNode(Node* pN) {
    if (pN != NULL && *pN != NULL) {
      free(*pN);
      *pN = NULL;	
    }
  }

  // Dictionary
  // Exported reference type
  typedef struct DictionaryObj {
    Node* hashTable;
    int numItems;
  } DictionaryObj;

  // helper function
  Node findKey(Dictionary D, char* k) {  
    Node temp = D->hashTable[hash(k)];

    if( D==NULL ) {
      fprintf(stderr, "Dictionary Error: findKey() called on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
    }

    while (temp != NULL) {	       
      if (strcmp(temp->key, k)==0) {	
        return temp;		        
      }
      temp = temp->next;		
    }
    return NULL;		               
  }

// hash functions --------------------------------------------

  // rotate_left()
  // rotate the bits in an unsigned int
  unsigned int rotate_left(unsigned int value, int shift) {
    int sizeInBits = 8*sizeof(unsigned int);
    shift = shift & (sizeInBits - 1);  // remainder on division by sizeInBits
    if ( shift == 0 )
      return value;
      
    return (value << shift) | (value >> (sizeInBits - shift));
  }

  // pre_hash()
  // turn a string into an unsigned int
  unsigned int pre_hash(char* input) {  // input points to first char in string
    unsigned int result = 0xBAE86554;  // = 10111010111010000110010101010100
    while (*input) {                   // while *input is not '\0' (not end of string)
      result ^= *input++;                // result = result ^ *input (current char alters result)
      // input++  (go to next char)
      result = rotate_left(result, 5);   // rotate result by fixed amount
    }
    return result;  // result is now a random looking bit pattern depending on input string
  }

  // hash()
  // turns a string into an int in the range 0 to tableSize-1
  int hash(char* key) {
    return pre_hash(key)%tableSize;
  }

// public functions -------------------------------------------

  // newDictionary()
  // constructor for the Dictionary type
  Dictionary newDictionary(void) {
    Dictionary D = malloc(sizeof(Dictionary));
    assert(D != NULL);
    D->hashTable = calloc(tableSize,sizeof(Node)); // array of Nodes of length tableSize
    assert(D->hashTable != NULL);
    D->numItems = 0;
    return D;
  }

  // freeDictionary()
  // destructor for the Dictionary type
  void freeDictionary(Dictionary* pD) {
    if(pD != NULL && *pD != NULL) {
      if(!isEmpty(*pD)) {
        makeEmpty(*pD);
	free((*pD)->hashTable);
        *pD = NULL;
        free(*pD);
      }
    }
  } 

  // isEmpty()
  // returns 1 (true) if D is empty, 0 (false) otherwise
  // pre: none
  int isEmpty(Dictionary D) {
    if (D == NULL) {
      fprintf(stderr, "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
    }
    if (D->numItems > 0) {
      return 0;
    }
    return 1;
  }

  // size()
  // returns the number of (key, value) pairs in D
  // pre: none
  int size(Dictionary D) {
    return D->numItems;
  }

  // lookup()
  // returns the value v such that (k, v) is in D, or returns NULL if no
  // such value v exists.
  // pre: none
  char* lookup(Dictionary D, char* k) {
    Node temp = D->hashTable[hash(k)];

    if (D == NULL) {
      fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary\n");
      exit(EXIT_FAILURE);
    }

    while (temp != NULL) {
      if (strcmp(temp->key, k) == 0) {
        return temp->value;
      }
      temp = temp->next;
    }
    return NULL;;
  }

  // insert()
  // inserts new (key,value) pair into D
  // pre: lookup(D, k)==NULL
  void insert(Dictionary D, char* k, char* v) {
    if( lookup(D, k) != NULL ) {
      fprintf(stderr,"Dictionary Error: cannot insert() duplicate key: \"%s\"\n", k);
      exit(EXIT_FAILURE);
    }
    if (D->hashTable[hash(k)] == NULL) {
      D->hashTable[hash(k)] = newNode(k, v);
      D->numItems++;
    } 
    else {
      Node temp = newNode(k, v);
      temp->next = D->hashTable[hash(k)]; // inserts from the front
      D->hashTable[hash(k)] = temp;
      D->numItems++;
    }
  }

  // delete()
  // deletes pair with the key k
  // pre: lookup(D, k)!=NULL
  void delete(Dictionary D, char* k) {
    if (lookup(D, k) == NULL) {
      fprintf(stderr, "Dictionary error: key not found\n");
      exit(EXIT_FAILURE);
    }
    Node temp = D->hashTable[hash(k)];

    if (strcmp(temp->key, k) == 0) {
      Node P = D->hashTable[hash(k)];
      Node G = P->next;
      D->hashTable[hash(k)] = G;
      freeNode(&P);
    }
    else{
      while (temp != NULL && temp->next != NULL) {
        if (strcmp(temp->next->key, k) == 0) {
          Node G = temp;
          Node C = temp->next;
          G->next = C->next;
          temp = G;
          freeNode(&C);
        }
        temp = temp->next;
      }
    }
    D->numItems--;
  }

  // makeEmpty()
  // re-sets D to the empty state.
  // pre: none
  void makeEmpty(Dictionary D) {
    int index;
    for(index = 0; index < tableSize; index++) {
      while(D->hashTable[index] != NULL) {
        Node temp;
        temp = D->hashTable[index];
        D->hashTable[index] = temp->next;
        freeNode(&temp);
        temp = NULL;
      }
    }
    D->numItems = 0;
  }

  // printDictionary()
  // pre: none
  // prints a text representation of D to the file pointed to by out
  void printDictionary(FILE* out, Dictionary D) {
    Node temp;
    int index = 0;

    if (D == NULL) {
      fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
    }
    for (index=0; index<tableSize; index++) {
      temp = D->hashTable[index];
      while (temp!=NULL) {
        fprintf(out, "%s %s \n", temp->key,temp->value);
        temp = temp->next;
      }
    }
  }
