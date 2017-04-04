/*
 * Queue.java
 * Array based implementation of IntegerQueue ADT (with array doubling)
 *
 */

class Queue implements QueueInterface{

// private inner Node class
  private class Node {
    Object item;
    Node next;

    Node(Object x){
      item = x;
      next = null;
    }
  }

  // Fields for the Queue class
  private Node head;     // reference to first Node in Queue
  private int numItems;  // number of items in this Queue

  // Queue()
  // constructor for the Queue class
  public Queue(){
    head = null;
    numItems = 0;
  }

  // isEmpty()
  // pre: none
  // post: returns true if this Queue is empty, false otherwise
  public boolean isEmpty(){
    return(numItems == 0);
  }
   
  // length()
  // pre: none
  // post: returns the length of this Queue.
  public int length(){
    return numItems;
  }

  // enqueue()
  // adds newItem to back of this Queue
  // pre: none
  // post: !isEmpty()
  public void enqueue(Object newItem){
    if( head == null ){
      head = new Node(newItem);
    }
    else {
      Node temp = head;
      while ( temp != null){
        if (temp.next == null){
	  break;
        }
	temp = temp.next;
      } 
      temp.next = new Node(newItem);
      numItems++;
    }
  }
  
  // dequeue()
  // deletes and returns item from front of this Queue
  // pre: !isEmpty()
  // post: this Queue will have one fewer element
  public Object dequeue() throws QueueEmptyException{
    if( head == null ){
      throw new QueueEmptyException("cannot dequeue() empty queue");
    }
    else{
      Node temp = head;
      head = temp.next;
      numItems--;
      return temp.item;
    }
  }
  
  // peek()
  // pre: !isEmpty()
  // post: returns item at front of Queue
  public Object peek() throws QueueEmptyException{
    if( head == null ){
      throw new QueueEmptyException("cannot peek() empty queue");
    }
    return head.item; //returns the first element of Queue
  }

  // dequeueAll()
  // sets this Queue to the empty state
  // pre: !isEmpty()
  // post: isEmpty()
  public void dequeueAll() throws QueueEmptyException{
    if( head==null ){
      throw new QueueEmptyException("cannot dequeueAll() empty queue");
    }
    numItems = 0;
    head = null;
  }

  // toString()
  // overrides Object's toString() method
  public String toString(){
    String s = "";
    Node temp = head;
    while(temp!=null){
      s += temp.item + " ";
      temp = temp.next;
    }
    return s;
  }
}
