package stackInJava;

import java.util.Stack;

public class remove {
    public static void insertBottom(Stack<Integer>st,int idx){
        if(st.size()==idx){
            st.pop();
            return;
        }
        int top=st.pop();
        insertBottom(st,idx);
        st.push(top);
    }
    public static void main(String[] args) {
        Stack<Integer>st=new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        insertBottom(st, 2);
        System.out.println(st);
    }
}
