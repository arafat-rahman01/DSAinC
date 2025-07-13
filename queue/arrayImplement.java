package queue;

public class arrayImplement {
    public static class queueA{
        int f=-1;
        int r=-1;
        int size=0;
        int[] arr=new int[5];
        public void add(int val){
            if(r==arr.length-1){
                System.out.println("Queue is Full!");
                return;
            }
            if(f==-1){
                f=r=0;
                arr[0]=val;
            }else{
                arr[++r]=val;
            }
            size++;
        }
        public int remove(){
            if(size==0){
                System.out.println("Queue id Empty..!");
                return -1;
            }
            f++;
            size--;
            return arr[f-1];
        }
        public int peek(){
            if(size==0){
                System.out.println("Queue id Empty..!");
                return -1;
            }
            return arr[f]; 
        }
        public void display(){
            if(size==0){
                System.out.println("Queue is empty..!");
                return;
            }else{
                for(int i=f;i<=r;i++){
                    System.out.println(arr[i]+" ");
                }
                System.out.println();
            }
        }
    }
    public static void main(String[] args) {
        queueA q=new queueA();
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.display();
        q.remove();
        q.display();
        q.remove();
        q.display();
        q.add(5);
        q.add(6);
        q.display();
    }
}