class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        
        HashMap<String, BiFunction<Integer, Integer, Integer>> mapa = new HashMap<>();
        
        mapa.put("+", (a, b) -> a + b);
        mapa.put("-", (a, b) -> a - b);
        mapa.put("*", (a, b) -> a * b);
        mapa.put("/", (a, b) -> a / b);
        
        for(String str : tokens) {
            if(str.equals("-") || str.equals("+") || str.equals("/") || str.equals("*")) {
                int b = stack.peek();
                stack.pop();
                int a = stack.peek();
                stack.pop();
                
                int rez = mapa.get(str).apply(a, b);
                stack.push(rez);
            } else {
                stack.push(Integer.parseInt(str));
            }
        }
        return stack.peek();
    }
}
