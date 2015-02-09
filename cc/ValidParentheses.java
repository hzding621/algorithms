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
                
                if (c==']') {
                    if (stack.empty() == true || stack.peek() != '[')
                        return false;
                    stack.pop();
                }
                
                if (c=='}') {
                    if (stack.empty() == true || stack.peek() != '{')
                        return false;
                    stack.pop();
                }
            }
        }
        return stack.empty() == true;