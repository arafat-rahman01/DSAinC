package Tree;

    // Node class
class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

// BinaryTree class
public class BinaryTree {
    Node root;

    // Inorder traversal (Left -> Root -> Right)
    void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }

    // Main method to test the tree
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        // Tree structure:
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5

        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("Inorder traversal of binary tree:");
        tree.inorder(tree.root);
    }
}

