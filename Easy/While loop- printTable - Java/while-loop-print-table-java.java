//{ Driver Code Starts
//Initial Template for Java
//Initial Template for C++
//Initial Template for C++

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
		
		//taking input using Scanner class
		Scanner sc = new Scanner(System.in);
		
		//taking count of total testcases
		int t=sc.nextInt();
		while(t-->0)
		{
		    //taking n
		    int n =sc.nextInt();
		    
		    //creating an object of class Geeks
		    Geeks obj=new Geeks();
		    
		    //calling printTable() method
		    //of class Geeks and passing
		    //n as an argument
		    obj.printTable(n);
		}
	
		
	}
}
// } Driver Code Ends

class Geeks {
    public static void printTable(int n) {
        int multiplier = 10;
        while (multiplier >= 1) {
            int result = n * multiplier;
            System.out.print(result + " ");
            multiplier--;
        }
        System.out.println(); // Print an empty line after the loop
    }
}