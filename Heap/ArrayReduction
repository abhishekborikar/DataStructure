package HealthTap;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.stream.Collectors;

/*
 Question :
 An Array is taken as input. Each time the initial 2 elements of the array is removed and their is sum is added to array.
 Find the cost of the array addition.
 eg. [1,2,3]
 1+2 = 3, [3,3]
 3+3 = 6, [6]
 total cost = 3+ 6 = 9
*/

public class ArrayReduction {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = in.nextInt();
        }

        int s = reductionCost(num);
        System.out.print(s);

    }

    static int reductionCost(int[] num) {

        Arrays.sort(num);
        ArrayList<Integer> n = (ArrayList<Integer>) Arrays.stream(num).boxed().collect(Collectors.toList());

        //priority queue
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        pq.addAll(n);
        int sum = 0;
        ArrayList<Integer> al = new ArrayList<Integer>();

        while(pq.size()!=1){
            Integer o = pq.poll();
            Integer s = pq.poll();
            pq.add(o+s);
            al.add(o+s);
        }

        int total = al.stream().mapToInt(i -> i.intValue()).sum();
        return total;
    }

}
