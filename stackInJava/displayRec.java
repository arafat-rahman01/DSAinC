package stackInJava;

import java.util.Stack;

public class displayRec {
    public static void display(Stack<Integer>s){
        if(s.size()==0) return;
        int top=s.pop();
        display(s);
        System.out.print(top+" ");
        s.push(top);
    }
    public static void main(String[] args) {
        Stack<Integer> st=new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        display(st);
    }
}
