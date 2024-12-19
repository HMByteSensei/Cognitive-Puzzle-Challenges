class Pair {
    public int first;
    public int second;
    
    Pair(int x, int y) {
        first = x;
        second = y;
    }
}

class Solution {
    public int[] dailyTemperatures(int[] t) {
        Stack<Pair> stack = new Stack<>();
        
        int[] rez = new int[t.length];
        
        for(int i=t.length-1; i>=0; i--) {
            if(stack.isEmpty() || t[i] < stack.peek().first) {
                if(stack.isEmpty()) {
                    stack.push(new Pair(t[i], i));
                    rez[i] = 0;
                    continue;
                }
                rez[i] = stack.peek().second - i;
                stack.push(new Pair(t[i], i));
            } else {
                while(!stack.isEmpty() && stack.peek().first <= t[i]) {
                    stack.pop();
                }
                if(!stack.isEmpty()) {
                    rez[i] = stack.peek().second - i;
                } else {
                    rez[i] = 0;
                }
                stack.push(new Pair(t[i], i));
            }
            
        }
        return rez;
    }
}
