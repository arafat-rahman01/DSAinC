package stackInJava;

public class linkedListImplement {

    // Make Stack class static so it can be used from main
    static class Stack {
        // Node class for linked list
        private class Node {
            int data;
            Node next;

            Node(int data) {
                this.data = data;
                this.next = null;
            }
        }

        // Top of the stack
        private Node top;

        // Constructor
        public Stack() {
            top = null;
        }

        // Push operation
        public void push(int value) {
            Node newNode = new Node(value);
            newNode.next = top;
            top = newNode;
        }

        // Pop operation
        public int pop() {
            if (isEmpty()) {
                throw new RuntimeException("Stack Underflow - Cannot pop from an empty stack");
            }
            int poppedValue = top.data;
            top = top.next;
            return poppedValue;
        }

        // Peek operation
        public int peek() {
            if (isEmpty()) {
                throw new RuntimeException("Stack is empty - Cannot peek");
            }
            return top.data;
        }

        // Check if the stack is empty
        public boolean isEmpty() {
            return top == null;
        }

        // Display stack (for testing)
        public void display() {
            Node temp = top;
            System.out.print("Stack: ");
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();  // Output: Stack: 30 20 10

        System.out.println("Top element is: " + stack.peek());  // Output: 30

        System.out.println("Popped element: " + stack.pop());  // Output: 30
        stack.display();  // Output: Stack: 20 10

        System.out.println("Is stack empty? " + stack.isEmpty());  // Output: false
    }
}
