/*
 * Title: Main.java
 * Abstract: This is a Java sample program to show the usage of tools in CST370.
 *           It reads two integer numbers from a user and displays their multiplication.
 * ID: 1010
 * Name: Dr. Byun
 * Date: 06/11/2024
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        
        System.out.println("Result: " + (num1 * num2));

        scanner.close();
    }
}

