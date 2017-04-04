/*
 * DictionarTest.java
 * A test client for the Dictionary ADT
 *
 */


class DictionaryTest{

  public static void main(String[] args){
    Dictionary A = new Dictionary();
    System.out.println(A.isEmpty());
    System.out.println(A.size());
    A.insert("2", "R");
    System.out.println(A);
    System.out.println(A.isEmpty());
    System.out.println(A.size());
    System.out.println();
    A.insert("3","S");
  
    A.insert("5", "A");
    A.insert("7","ENC");
    A.insert("11" , "RYP");
    A.insert("13", "TION");
    //A.insert("2", "hello"); throws exception
    System.out.println(A);
    System.out.println("Size of Dictionary A:"+ A.size());
  
    System.out.println();

    System.out.println("Value of key 3: " + A.lookup("3"));
    System.out.println();


    A.delete("7");
    System.out.println(A);
    System.out.println("Size of Dictionary A: "+ A.size());

    A.delete("13");
    System.out.println(A);
    System.out.println("Size of Dictionary A: " + A.size());

    A.makeEmpty();
    System.out.println("Size of Dictionary A: "+A.size());
    System.out.println(A.isEmpty());
  }
}
