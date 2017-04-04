/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - pa3
 *
 * Dictionary.java
 * Dictionary ADT uses linked list data structure
 */

public class Dictionary implements DictionaryInterface {

  // private inner Node class
  private class Node {
    String key;
    String value;
    Node next;

    Node(String key, String value) {
      this.key = key;
      this.value = value;
      next = null;
    }
  }

  // Fields for the IntegerList class
  private Node head; 
  private int numItems;

  // Dictionary()
  // constructor for the Dictionary class
  public Dictionary() {
    head = null;
    numItems = 0;
  }


// private helper function -------------------------------------------------

  // find()
  // returns a reference to the Node at position index in this Dictionary
  private Node findKey(String key) {
    Node N = head;

    while (N != null) {	
      if(N.key == key) {	
        return N;		
      }
      N = N.next;		
    }
    return null;		
  }

// ADT operations ----------------------------------------------------------

  // isEmpty()
  // pre: none
  // post: returns true if this Dictionary is empty, false otherwise
  public boolean isEmpty() {
    return (numItems == 0);
  }

  // size()
  // pre: none
  // post: returns the number of elements in this IntegerList
  public int size() {
    return numItems;
  }

  // lookup()
  // pre: 1 <= index <= size()
  // post: returns item at position index in this IntegerList
  public String lookup(String key) {
    Node N = head;

    while (N != null) {
      if (N.key == key) {
        return N.value;
      }
      N = N.next;
    }
    return null;
  }

  // insert()
  // inserts newItem into this IntegerList at position index
  // pre: 1 <= index <= size()+1
  // post: !isEmpty(), items to the right of newItem are renumbered
  public void insert(String key, String value) {

    if (lookup(key) != null) {
      throw new DuplicateKeyException("cannot insert duplicate keys");
    }

    // if there is nothing in dictionary, create new node
    if (head == null){ 
      Node N = new Node(key, value);
      N.next = head;
      head = N;
      numItems++;
    }
    else {
      Node N = head;
      // checks for next place to place a node
      while (N != null){ 
        if (N.next == null) { 
          break;
        }
        N = N.next;
      }
      N.next = new Node(key, value);	 
      numItems++;
    }
  } 

  // delete()
  // deletes item at position index from this IntegerList
  // pre: 1 <= index <= size()
  // post: items to the right of deleted item are renumbered
  public void delete(String key) throws KeyNotFoundException {

    if (lookup(key) == null) {
      throw new KeyNotFoundException("cannot delete non-existent key");
    }
    
    // when theres only one node in dictionary, removes it
    if (numItems <= 1) { 
      Node N = head;
      head = head.next;
      N.next = null;
    } 
    else {
      Node N = head;
      Node P = findKey(key);
      if(N.key == key){
        head = P.next;
      }
      else{
        while(N.next.key != key){
	  N = N.next;
        }
	N.next = N.next.next;
      }
    }
    numItems--;
  }

 

  // makeEmpty()
  // pre: none
  // post: isEmpty()
  public void makeEmpty() {
    head = null;
    numItems = 0;
  }

  // toString()
  // pre: none
  // post:  prints current state to stdout
  // Overrides Object's toString() method
  public String toString(){
  
    String s = "";
    Node N = head;
    while (N != null) {
      s += N.key + " " + N.value + "\n";
      N = N.next;
    }
    return s;
  }

}
