package BST_CODE;

import java.util.Scanner;

class Node{
    int data;
    Node left,right;

    public Node(int val){
        data=val;
        left=right=null;
    }
}

public class insert {
    Node root;

    Node inst(Node root,int val){
        if(root==null){
            return new Node(val);
        }
        if(val<root.data){
            root.left=inst(root.left, val);
        }
        else if(val>root.data){
            root.right=inst(root.right, val);
        }
        return root;
    }

    void inOrder(Node root){
        if(root==null) return;
        inOrder(root.left);
        System.out.println(root.data+" ");
        inOrder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        insert tree=new insert();
        int n=sc.nextInt();

        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            tree.root=tree.inst(tree.root,x);
        }

        tree.inOrder(tree.root);
    }
}


