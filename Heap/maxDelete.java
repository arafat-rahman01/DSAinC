package Heap;

public class maxDelete {
    public static void heapifyDown(int[] heap, int n, int i) {
        int largest = i;
        int left = 2 * i + 1; // left child
        int right = 2 * i + 2; // right child

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapifyDown(heap, n, largest);
        }
    }

    public static int deleteMax(int[] heap, int n) {
        if (n <= 0) return -1;

        int max = heap[0];
        heap[0] = heap[n - 1]; // Last element goes to root
        heapifyDown(heap, n - 1, 0);
        return max;
    }

    public static void main(String[] args) {
        int[] heap = {50, 30, 40, 10, 20, 35, 25};
        int n = heap.length;

        int deleted = deleteMax(heap, n);

        System.out.println("Deleted Max: " + deleted);
        System.out.print("Updated Heap: ");
        for (int i = 0; i < n - 1; i++) {
            System.out.print(heap[i] + " ");
        }
    }
}
