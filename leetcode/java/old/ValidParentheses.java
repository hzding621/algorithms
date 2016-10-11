import java.util.Stack;

public class ValidParentheses {

    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else {
                if (c==')') {
                    if (stack.empty() == true || stack.peek() != '(')
                        return false;
                    stack.pop();
                }

                else if (c==']') {
                    if (stack.empty() == true || stack.peek() != '[')
                        return false;
                    stack.pop();
                }

                else if (c=='}') {
                    if (stack.empty() == true || stack.peek() != '{')
                        return false;
                    stack.pop();
                }

                else {
                    return false;
                }
            }
        }
        return stack.empty() == true;
    }

    public static void main(String[] args) {
        System.out.println(isValid("{{}}[]()"));
    }
}

