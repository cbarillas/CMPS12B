/*
 * QueueTest.java
 * Client tests for my Queue ADT
 *
 */

class QueueTest{
  public static void main (String[] args){
    Queue A = new Queue();
    
    System.out.println("queue A is empty? "+A.isEmpty());
    
    // place into queue
    A.enqueue((int)1);
    A.enqueue((int)1);
    A.enqueue((int)2);
    A.enqueue((int)3);
    A.enqueue((int)5);
    A.enqueue((int)8);
    A.enqueue((int)13);
    A.enqueue((int)21);
    A.enqueue((int)34);
   

   
    System.out.println("queue A is empty?"+A.isEmpty());
    System.out.println("length of queue A: "+A.length());
    System.out.println("queue A: "+A);

    // remove an element from queue 
    A.dequeue();
    A.dequeue();
    
    System.out.println("length of queue A: "+A.length());
    System.out.println("queue A: "+A);
    System.out.println("element at front of queue A is: "+A.peek()); 
    //throws exception
    //A.dequeueAll();
    //System.out.println(A.peek);
  }
}
