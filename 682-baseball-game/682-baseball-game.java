class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stk = new Stack<Integer>();
        int sum = 0;
        
        for(String op : ops) {
            if(op.equals("+")) {
                int first = stk.peek();
                stk.pop();
                int second = stk.peek();
                int cur = first + second;
                
                stk.push(first);
                stk.push(cur);
                sum += cur;
            }
            else if(op.equals("D")) {
                int d = stk.peek() * 2;
                stk.push(d);
                sum += d;
            }
            else if(op.equals("C")) {
                sum -= stk.peek();
                stk.pop();
            }
            else {
                int num = Integer.parseInt(op);
                stk.push(num);
                sum += num;
            }
        }
        
        return sum;
    }
}