package Heap;
import java.util.PriorityQueue;
import java.util.Collections;

public class maxHeap {
    public static void main(String[] args) {
        PriorityQueue<Integer> maxH=new PriorityQueue<>(Collections.reverseOrder());

        maxH.add(10);
        maxH.add(30);
        maxH.add(20);
        maxH.add(5);

        while (!maxH.isEmpty()) {
            System.out.println(maxH.poll()+" ");
        }
    }
}
