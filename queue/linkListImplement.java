

public class linkListImplement {
    public static class Node {
        int val;
        Node next;
        Node(int val){
            this.val=val;
        }
    }
    public static class queueLL{
        Node head=null;
        Node tail=null;
        int size=0;
        public void add(int val){
            Node temp=new Node(val);
            if(size==0){
                head=tail=temp;
            }else{
                tail.next=temp;
                tail=temp;
            }
            size++;
        }

        public int peek(){
            if(size==0){
                System.out.println("Queue is Empty..!");
                return -1;
            }
            return head.val;
        }

        public int remove(){
            if(size==0){
                System.out.println("Queue is Empty..!");
                return -1;
            }
            int x=head.val;
            head=head.next;
            size--;
            return x;
        }

        public void display(){
            if(size==0){
                System.out.println("Queue is empty..!");
                return;
            }
            Node temp=head;
            for(int i=0;i<size;i++){
                System.out.println(temp.val+" ");
                temp=temp.next;
            }
            System.out.println();
        }
        public boolean isEmpty(){
            if(size==0) return true;
            else return false;
        }
    }

    public static void main(String[] args) {
        queueLL q=new queueLL();
        System.out.println(q.isEmpty());
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.display();
        System.out.println(q.isEmpty());
        System.out.println(q.peek());
        System.out.println();
        q.remove();
        q.display();
    }
}
