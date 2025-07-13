package stackInJava;

import java.util.Stack;

public class insertAtAnyIndex {
    public static void main(String[] args) {
        Stack<Integer> st=new Stack<>();
        st.push(10);
        st.push(20);
        st.push(40);
        st.push(50);
        System.out.println(st);
        int idx=2;
        int value=30;
        Stack<Integer>temp=new Stack<>();
        while (st.size()>idx) {
            temp.push(st.pop());
        }
        System.out.println(st);
        st.push(value);
        System.out.println(st);
        System.out.println(temp);
        while(temp.size()>0){
            st.push(temp.pop()); 
        }
        System.out.println(st);
        System.out.println(temp);
    }
}
