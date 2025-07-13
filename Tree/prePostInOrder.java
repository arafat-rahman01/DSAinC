// File: Tree/prePostInOrder.java
package Tree;

public class prePostInOrder {

    // Node class (inner class)
    static class Node {
        int data;
        Node left, right;

        Node(int value) {
            data = value;
            left = right = null;
        }
    }

    // Inorder traversal (Left → Root → Right)
    static void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }

    // Preorder traversal (Root → Left → Right)
    static void preorder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preorder(node.left);
            preorder(node.right);
        }
    }

    // Postorder traversal (Left → Right → Root)
    static void postorder(Node node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);
            System.out.print(node.data + " ");
        }
    }

    // Main method
    public static void main(String[] args) {
        /*
                Tree Structure:
                    1
                   / \
                  2   3
                 / \
                4   5
        */

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        System.out.println("Inorder traversal:");
        inorder(root);

        System.out.println("\nPreorder traversal:");
        preorder(root);

        System.out.println("\nPostorder traversal:");
        postorder(root);
    }
}
