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

public class Search {
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

    boolean search(Node root,int key){
        if(root==null) return false;
        if(root.data==key) return true;
        if(root.data>key){
            return search(root.left, key);
        }else{
            return search(root.right, key);
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Search tree=new Search();   //Search er er class tar object
        int n=sc.nextInt();

        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            tree.root=tree.inst(tree.root,x);
        }

        int key=sc.nextInt();
        System.out.println(tree.search(tree.root,key)?"FOUND "+ key:"NOT FOUND");
    }
}


