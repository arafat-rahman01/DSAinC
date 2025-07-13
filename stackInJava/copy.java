package stackInJava;
import java.util.Stack;
import java.util.Scanner;
public class copy{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Stack<Integer> st=new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        System.out.println(st);
         
        Stack<Integer>rt=new Stack<>();
        while(st.size()>0){           
            rt.push(st.pop());            
        }

        Stack<Integer>ss=new Stack<>();
        while(rt.size()>0){           
            ss.push(rt.pop());
            
        }
        System.out.println(ss);

    }
}
