class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string& t : tokens) {
            if (isdigit(t.back())) {
                nums.push(stoi(t));
                continue;
            }

            int second = nums.top();
            nums.pop();
            int first = nums.top();
            nums.pop();

            if (t == "+") {
                nums.push(first + second);
            }
            else if (t == "-") {
                nums.push(first - second);
            }
            else if (t == "*") {
                nums.push(first * second);
            }
            else if (t == "/") {
                nums.push(first / second);
            }
        }

        return nums.top();
    }
};