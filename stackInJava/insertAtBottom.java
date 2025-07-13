package stackInJava;

import java.util.Stack;

public class insertAtBottom {
    public static void insertBottom(Stack<Integer>st,int val){
        if(st.size()==0){
            st.push(val);
            return;
        }
        int top=st.pop();
        insertBottom(st,val);
        st.push(top);
    }
    public static void main(String[] args) {
        Stack<Integer>st=new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        insertBottom(st, 4);
        System.out.println(st);
    }
}
