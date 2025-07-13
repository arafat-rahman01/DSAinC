import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class csubtreePrint {
    Node root;

    Node insert(Node root, int val) {
        if (root == null) return new Node(val);
        if (val < root.data)
            root.left = insert(root.left, val);
        else
            root.right = insert(root.right, val);
        return root;
    }

    // এই function টা key খুঁজে ওই node return করে
    Node search(Node root, int key) {
        if (root == null) return null;
        if (root.data == key) return root;
        if (key < root.data)
            return search(root.left, key);
        else
            return search(root.right, key);
    }

    // এই function টা দিয়ে আমরা key পেলে subtree টা প্রিন্ট করবো
    void printSubtree(Node node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        printSubtree(node.left);
        printSubtree(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        code tree = new code();

        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            tree.root = tree.insert(tree.root, x);
        }

        int key = sc.nextInt();

        Node keyNode = tree.search(tree.root, key);
        if (keyNode != null) {
            System.out.println("Subtree starting from key " + key + ":");
            tree.printSubtree(keyNode);
        } else {
            System.out.println("Key not found in the tree.");
        }
    }
}
