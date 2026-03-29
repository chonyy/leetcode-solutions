class MinStack {
    private Stack<Integer> normal = new Stack<>();
    private Stack<Integer> min = new Stack<>();

    public MinStack() {
        
    }
    
    public void push(int val) {
        normal.push(val);

        if (min.empty() || val <= min.peek()) {
            min.push(val);
        }
    }
    
    public void pop() {
        if (normal.peek().equals(min.peek())) {
            min.pop();
        }
        normal.pop();
    }
    
    public int top() {
        return normal.peek();
    }
    
    public int getMin() {
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


//  normal: -2 0 -3
//  min: -2 -3