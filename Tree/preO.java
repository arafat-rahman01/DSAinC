package Tree;

public class preO{
    static class Node{
        int data;
        Node left,right;
        Node(int data){
            this.data=data;
            left=right=null;
        }
    }

    public static int sum(Node node){
        if(node==null) return 0;
        return node.data+sum(node.left)+sum(node.right);

    }

    public static int size(Node node){
        if(node==null) return 0;
        return 1+size(node.left)+size(node.right);
    }

    public static int min(Node node){
        if(node==null) return Integer.MAX_VALUE;
        return Math.min(node.data, Math.min(min(node.left), min(node.right))); 
    }

    static void inorder(Node node){
        if(node!=null){
            inorder(node.left);
            System.out.print(node.data+" ");
            inorder(node.right);
        }
    }
    
    public static void main(String[] args) {
        Node root=new Node(1);
        root.left=new Node(2);
        root.right=new Node(3);
        root.left.left=new Node(4);
        root.left.right=new Node(5);
        System.out.println("Inorder traverseSal");
        inorder(root);
        System.err.println();
        System.out.println(size(root));
        System.out.println();
        System.out.println(sum(root));
        System.out.println();
        System.out.println(min(root));
    }
}
