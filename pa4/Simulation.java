/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - pa4
 *
 * Simulation.java
 */


import java.io.*;
import java.util.Scanner;

class Simulation {
  public static void main(String[] args) throws IOException {

    // declaring variables
    Scanner inputFile = null;
    PrintWriter report = null;
    PrintWriter trace = null;
    Queue Storage = new Queue();
    int m = 0;
    int time = 0;

    // checks command line arguments
    if (args.length != 1) {
      System.out.println("Usage: Simultation infile");
      System.exit(1);
    }

    // opens files for reading and writing
    inputFile = new Scanner(new File(args[0]));
    report = new PrintWriter(new FileWriter(args[0] + ".rpt"));
    trace = new PrintWriter(new FileWriter(args[0] + ".trc"));

    // gets number of jobs
    m = numOfJobs(inputFile);

    while(inputFile.hasNextLine()) {
      Storage.enqueue((Job) getJob(inputFile));
    }

    // writes to trace and report files
    trace.println("Trace file: " + (args[0] + ".trc"));
    trace.println(m + " Jobs:");
    trace.println(Storage);
    trace.println();

    report.println("Report file: " + (args[0] + ".rpt"));
    report.println(m + " Jobs:");
    report.println(Storage);
    report.println();
    report.println("***********************************************************");
		
    // did not finish this part 
    //
    //
    //
    //
    //
		
    inputFile.close();
    report.close();
    trace.close();
  }

  // returns number of jobs to be completed
  public static int numOfJobs(Scanner inputFile) { 
    String s = inputFile.nextLine();
    int x = Integer.parseInt(s);
    return x;
  }

  // provided in simulation stub
  public static Job getJob(Scanner in) { 
    String[] s = in.nextLine().split(" ");
    int a = Integer.parseInt(s[0]);
    int d = Integer.parseInt(s[1]);
    return new Job(a, d);
  }
}
