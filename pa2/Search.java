/*
 *
 * Search.java
 * If target word is found in a file then it prints out it was found.
 * compile: % make
 *          % Search <input_file> target1 [target2 ..] 
 *
 */

import java.io.*;
import java.util.Scanner;


class Search{
	
  public static void main(String[] args) throws IOException{

    //Checks is there are enough arguments
    if(args.length < 2){
      System.err.println("Usage: Search file target1 [target2..]");
      System.exit(1);
    }

    //Scans and counts the number of lines in the file
    Scanner fileIn = new Scanner(new File(args[0]));
    int numOfLines = 0;
    String line = null;

    while( fileIn.hasNextLine() ){			
      numOfLines++;				
      line = fileIn.nextLine();		
    }

    //intialize's the length of the String and int array
    String[] strngArry = new String[numOfLines];
    int[] lineNumber = new int[numOfLines];
    fileIn = new Scanner(new File(args[0]));	/*re-scans the file*/

    //adds number to the array
    for(int i=1; i<=lineNumber.length; i++){
      lineNumber[i-1] = i;
    }

    //Scans the file, putting the word in the String array
    for(int i =0; fileIn.hasNextLine(); i++){
      line = fileIn.nextLine();
      strngArry[i] = line;
    }

    //puts the string Array in order
    mergeSort(strngArry,lineNumber, 0, strngArry.length-1);

    //prints if the target is found and on what line
    for(int i=1; i<args.length; i++){
      System.out.println(binarySearch(strngArry, lineNumber, 0, strngArry.length-1, args[i]));
      fileIn.close();
    }
  }


  // mergeSort()
  // sort subarray A[p...r]
  public static void mergeSort(String[] word, int[] lineNumber, int p, int r){
    int q;
    if(p < r) {
      q = (p+r)/2;
      mergeSort(word, lineNumber, p, q);
      mergeSort(word, lineNumber, q+1, r);
      merge(word, lineNumber, p, q, r);
    }
  }


  // merge()
  // merges sorted subarrays A[p..q] and A[q+1..r]
  public static void merge(String[] word, int[] lineNumber, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    String[] L = new String[n1];
    String[] R = new String[n2];
    int[] numLinesL = new int[n1];
    int[] numLinesR = new int[n2];
    int i, j, k;

    for(i=0; i<n1; i++){
      L[i] = word[p+i];
      numLinesL[i] = lineNumber[p+i];
    }

    for(j=0; j<n2; j++){
      R[j] = word[q+j+1];
      numLinesR[j] = lineNumber[q+j+1];
    }

    i = 0; j = 0;
    for(k=p; k<=r; k++){
      if( i<n1 && j<n2 ){
        if( L[i].compareTo(R[j]) < 0 ){
          word[k] = L[i];
          lineNumber[k] = numLinesL[i];
          i++;
        }
        else{
          word[k] = R[j];
          lineNumber[k] = numLinesR[j];
          j++;
        }
      }
      else if( i<n1 ){
        word[k] = L[i];
        lineNumber[k] = numLinesL[i];
        i++;
      }
      else{ // j<n2
        word[k] = R[j];
        lineNumber[k] = numLinesR[j];
        j++;
      }
    }
  }

  static String binarySearch(String[] word, int[] lineNumber, int p, int r, String target){
    int q;
    if(p > r){
      return target + " not found";
    }
    else{
      q = (p+r)/2;
      int compareValue = target.compareTo(word[q]);
      if(compareValue == 0){
        return target + " found on line " +lineNumber[q];
      }
      else if(compareValue < 0){
        return binarySearch(word, lineNumber, p, q-1, target);
      }
      else{
        return binarySearch(word, lineNumber, q+1, r, target);
      }
    }
  }
}
