class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();

        for (String t : tokens) {

            if (t.charAt(t.length()-1) >= '0' && t.charAt(t.length()-1) <= '9') {
                int num = Integer.parseInt(t);
                stk.push(num);
            }
            else {
                int num1 = stk.peek();
                stk.pop();
                int num2 = stk.peek();
                stk.pop();

                if (t.equals("+")) {
                    stk.push(num1 + num2);
                }
                else if (t.equals("-")) {
                    stk.push(num2 - num1);
                }
                else if (t.equals("*")) {
                    stk.push(num1 * num2);
                }
                else if (t.equals("/")) {
                    stk.push(num2 / num1);
                }
            }
        }

        return stk.peek();
    }
}