/* Carlos Barillas, cbarilla@ucsc.edu
 * CMPS 12B - lab 2
 * FileReverse.java
 * Illustrates file IO and tokenization of strings.
 * compile: % make
 *          % FileReverse <input_file> <output_file>
 */

import java.io.*;
import java.util.Scanner;

public class FileReverse{

  // stringReverse()
  // this function will return a String that is the reversal of the first n characters of s
  public static String stringReverse(String s, int n){
    // empty string to store reversed token
    String reversedString = "";					             
    if(n > 0){
      //concatenates string
      reversedString = s.charAt(n-1) + stringReverse(s, n-1);
    }
    //returns concatenated string
    return reversedString;
  }

  public static void main(String[] args) throws IOException{
    int lineNumber = 0;

    //check number of command line arguments is at least 2
    if(args.length < 2){
      System.out.println("Usage: FileCopy <input file> <output file>");
      System.exit(1);
    }

    // open files
    Scanner in = new Scanner(new File(args[0]));
    PrintWriter out = new PrintWriter(new FileWriter(args[1]));

    // read lines from in, extract and print tokens from each line
    while( in.hasNextLine() ){
      lineNumber++;

      // trim leading and trailing spaces, then add one trailing space so
      // split works on blank lines
      String line = in.nextLine().trim() + " ";

      // split line around white space
      String[] token = line.split("\\s+");

      // print out tokens
      int len = token.length;
      for(int i=0; i<len; i++){
        String temp = token[i];
        // stores reversed tokenized string
	String result = stringReverse(temp, temp.length());
	out.println(result);					
      }
    }
    // close files
    in.close();
    out.close();
  }
}
