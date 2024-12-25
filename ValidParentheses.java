class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        
        for(char ch : s.toCharArray()) {
            if(ch == ')' || ch == ']' || ch == '}') {
                if(!stack.isEmpty() && stack.peek() == ch) {
                    stack.pop();
                    continue;
                }
                return false;
            }
            
            switch(ch) {
                case '(':
                    ch = ')';
                    break;
                case '[':
                    ch = ']';
                    break;
                default:
                    ch = '}';
            }
            stack.push(ch);
        }
        return stack.isEmpty();
    }
}
