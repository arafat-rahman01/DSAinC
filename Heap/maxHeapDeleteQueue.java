package Heap;

import java.util.Collections;
import java.util.PriorityQueue;

public class maxHeapDeleteQueue {
    public static void main(String[] args) {
        // Max Heap using PriorityQueue
        PriorityQueue<Integer> maxH = new PriorityQueue<>(Collections.reverseOrder());

        // Adding elements to heap
        maxH.add(50);
        maxH.add(30);
        maxH.add(40);
        maxH.add(10);
        maxH.add(20);
        maxH.add(35);
        maxH.add(25);

        System.out.println("Max Heap: " + maxH);

        // Deleting the max (root)
        int deleted = maxH.poll(); // Removes and returns max

        System.out.println("Deleted Max: " + deleted);
        System.out.println("Heap after deletion: " + maxH);
    }
}
