package Heap;

import java.util.Scanner;

public class maxHeapArray {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of elemnts: ");
        int n=sc.nextInt();

        int[] A=new int[n+1];
        A[0]=0;

        for(int i=1;i<=n;i++){
            int temp=sc.nextInt();

            int k=i;
            while (k>1 && A[k/2]<temp) {
                A[k]=A[k/2];
                k=k/2;
            }
            A[k]=temp;
        }
        System.out.println("Max Heap");
        for(int i=1;i<=n;i++){
            System.out.println(A[i]+" ");
        }
    }
}


    // public static void main(String[] args) {
    //     int[] A = {0, 10, 20, 5, 6, 1, 8}; // index 0 unused for easier parent-child calculation
    //     int n = A.length - 1; // Because we are not using index 0

    //     // Heap construction begins
    //     for (int i = 2; i <= n; ++i) {
    //         int temp = A[i]; // Step 1: temp holds current element
    //         int k = i;

    //         // Step 2: Bubble up if parent is smaller (for max heap)
    //         while (k > 1 && A[k / 2] < temp) {
    //             A[k] = A[k / 2]; // Move parent's value down
    //             k = k / 2;       // Move up to parent's index
    //         }

    //         A[k] = temp; // Step 3: place temp in correct position
    //     }

    //     // Output the heap
    //     System.out.println("Heap Array:");
    //     for (int i = 1; i <= n; i++) {
    //         System.out.print(A[i] + " ");
    //     }
    // }

