package BST_CODE;
class Node{
    int data;
    Node left,right;

    Node(int val){
        data=val;
        left=right=null;
    }
}
public class delete {
    Node root;

    Node insert(Node root,int val){
        if(root==null){
            return new Node(val);
        }
        if(val<root.data){
            root.left=insert(root.left, val);
        }else {
            root.right=insert(root.right, val);
        }
        return root;
    }

    Node findMin(Node root){
        while(root.left!=null){
            root=root.left;
        }
        return root;
    }

    Node delete(Node root,int key){
        if(root==null) return null;
        if(key<root.data){
            root.left=delete(root.left, key);
        }
        else if(key>root.data){
            root.right=delete(root.right, key);
        }
        else{
            if(root.left==null){
                return root.right;
            }
            else if(root.right==null){
                return root.left;
            }

            Node temp=findMin(root.right);
            root.data=temp.data;
            root.right=delete(root.right, temp.data);
        }
        return root;
    }
    public static void main(String[] args) {
        
    }
}
