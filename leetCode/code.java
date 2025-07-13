///package leetCode;

import java.util.Scanner;


class Node {
        int data;
        Node left,right;
        Node(int val){
            data=val;
            left=right=null;
        }
        
    }
public class code {
    Node root;

    Node insert(Node root,int val){
        if(root==null){
            return new Node(val);
        }
        if(val<root.data){
            root.left=insert(root.left, val);
        }
        else{
            root.right=insert(root.right, val);
        }
        return root;
    }

    boolean search(Node root,int key){
        int a=0;
        if(root==null) return false;
        if(root.data==key || a==1){
            a=1;
            if(root!=null){
                System.out.println(key+" ");
                search(root.left, key);
                search(root.right, key);
            }                      
        }
        if(key<root.data) return search(root.left, key);
        else  return search(root.right, key);
        
        
    }
    

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        code tree=new code();
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            tree.root=tree.insert(tree.root, x);
        }
        int key=sc.nextInt();
        System.out.println(tree.search(tree.root, key));
    }
}
