/*
 * HelloUser2.java
 *
 */

public class HelloUser2 {	
  public static void main(String[] args) {
    String os = System.getProperty("os.name");
    String osVer = System.getProperty("os.version");
  
    System.out.println("This is my first lab in Java!");
    System.out.println("You are currently running " +os+" " +osVer+" on your computer.");
  }
}
