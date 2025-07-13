package stackInJava;

import java.util.Stack;

public class infixToPostfix {
    public static void main(String[] args) {
        String infix="9-(8*6/3)+8*2/2";  //CT_2

        Stack<String>val=new Stack<>();
        Stack<Character>op=new Stack<>();

        for(int i=0;i<infix.length();i++){
            char ch=infix.charAt(i);
            int ascii=(int)ch;

            if(ascii>=48 && ascii<=57){
                String s=""+ch;
                val.push(s);
            }
            else if(op.size()==0 || ch=='(' || op.peek()=='('){
                op.push(ch);
            }
            else if(ch==')'){
                while(op.peek()!='('){
                    String v2=val.pop();
                    String v1=val.pop();
                    char o=op.pop();
                    String t=v1+v2+o;
                    val.push(t);
                }
                op.pop();
            }
            else{
                if(ch=='+' || ch=='-'){
                    String v2=val.pop();
                    String v1=val.pop();
                    char o=op.pop();
                    String t=v1+v2+o;
                    val.push(t);
                   
                    op.push(ch);
                }
                if(ch=='/' || ch=='*'){
                    if(op.peek()=='*' || op.peek()=='/'){
                        String v2=val.pop();
                        String v1=val.pop();
                        char o=op.pop();
                        String t=v1+v2+o;
                        val.push(t);
                        
                        op.push(ch);
                    }
                    else op.push(ch);
                }
            }
        }
        while(val.size()>1){
            String v2=val.pop();
            String v1=val.pop();
            char o=op.pop();
            String t=v1+v2+o;
            val.push(t);
        }
        System.out.println(val.peek());
    }
}
