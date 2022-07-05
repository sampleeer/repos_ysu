package com.company;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

    public static int NOD(int a, int b) {
        while (b !=0) {
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String linne = in.nextLine();
        Integer a = 1,b= 2, chis = 0, znam = 0, num = 0;
        String[] parts = linne.split(" ");
        String[] first_numb = parts[0].split("/");
        String[] second_numb = parts[2].split("/");

        switch (parts[1]) {
            case  ("+"):
                chis=Integer.valueOf(first_numb[0])  * Integer.valueOf(second_numb[1])  + Integer.valueOf(first_numb[1])  * Integer.valueOf(second_numb[0]);
                znam=Integer.valueOf(first_numb[1]) * Integer.valueOf(second_numb[1]);
                break;
            case ("-"):
                chis=Integer.valueOf(first_numb[0])  * Integer.valueOf(second_numb[1])  - Integer.valueOf(first_numb[1])  * Integer.valueOf(second_numb[0]);
                znam=Integer.valueOf(first_numb[1]) * Integer.valueOf(second_numb[1]);
                break;
            case ("*"):
                chis=Integer.valueOf(first_numb[0])  * Integer.valueOf(second_numb[0]);
                znam=Integer.valueOf(first_numb[1]) * Integer.valueOf(second_numb[1]);
                break;
            case ("/"):
                chis=Integer.valueOf(first_numb[0])  * Integer.valueOf(second_numb[1]);
                znam=Integer.valueOf(first_numb[1]) * Integer.valueOf(second_numb[0]);
                break;
        }
        num = NOD(chis,znam);
        if(znam/num == 1){
            System.out.println(chis/num);
        }
        else
            System.out.println(chis/num + "/" +znam/num);

    }
}
