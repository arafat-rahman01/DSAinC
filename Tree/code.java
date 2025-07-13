package Tree;

public class code {
    static class Node{
        int data;
        Node left,right;

        Node(int value){
            data=value;
            left=right=null;
        }
    }

    static void inorder(Node node){
        if(node!=null){
            inorder(node.left);
            System.out.println(node.data+" ");
            inorder(node.right);
        }
    }

    static void preorder(Node node){
        if(node!=null){
            System.out.println(node.data+" ");
            preorder(node.left);
            preorder(node.right);
        }
    }

    static void postorder(Node node){
        if(node!=null){
            postorder(node.left);
            postorder(node.right);
            System.out.println(node.data);
        }
    }

    public static void main(String[] args) {
        Node root=new Node(1);
        root.left=new Node(2);
        root.right=new Node(3);
        root.left.left=new Node(4);
        root.left.right=new  Node(5);

        System.out.println("Inorder traversal");
        inorder(root);

        System.out.println("Preorder ");
        preorder(root);

        System.out.println("Post Order");
        postorder(root);
    }
}
