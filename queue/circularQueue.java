

public class circularQueue {
    int front=-1;
    int rear=-1;
    int size=0;
    int[] arr=new int[5];

    public void add(int val)throws Exception{
        if(size==arr.length){
            throw new Exception("Queue is full");
        }
        else if(size==0){
            front=rear=0;
            arr[0]=val;
        }
        else if(rear<arr.length-1){ //last index teke coto
            arr[++rear]=val;
        }
        else if(rear==arr.length-1){
            rear=0;
            arr[0]=val;
        }
        size++;
    }
    public int remove()throws Exception{
        if(size==0){
            throw new Exception("Queue is empty");
        }
        else if(front==arr.length-1){
            int val=arr[front];
            front=0;
            size--;
            return val;
        }
        else{
            int val=arr[front];
            front++;
            size--;
            return val;
        }
    }

    public int peek()throws Exception{
        if(size==0){
            throw new Exception("Queue is Empty..!");
        }
        else{
            return arr[front];
        }
    }

    public boolean isEmpty(){
        if(size==0) return true;
        else return false;
    }

    public void display(){
        if(size==0){
            System.out.println("Queue is Empty...!");
            return;
        }
        else if(front<=rear){
            for(int i=front;i<=rear;i++){
                System.out.println(arr[i]+" ");
            }
        }
        else{       //rear<front
            for(int i=front;i<arr.length;i++){
                //front to last index elements prints
                System.out.println(arr[i]+" ");
            }
            for(int i=0;i<=rear;i++){
                //0'th index to rear index elements prints
                System.out.println(arr[i]+" ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args)throws Exception {
        circularQueue q=new circularQueue();
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        q.display();
        q.remove();
        q.remove();
        q.remove();
        q.display();
        q.add(7);
        q.add(8);
        q.display();
    }
}
