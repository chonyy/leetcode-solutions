class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        stack<int> stk;

        stk.push(heights[n-1]);

        for (int i = n-2; i >= 0; i --) {
            int h = heights[i];
            int popCount = 0;
            while (!stk.empty() && stk.top() <= h) {
                stk.pop();
                popCount ++;
            }

            if (!stk.empty()) {
                popCount ++;
            }

            res[i] = popCount;
            stk.push(h);
        }

        return res;
    }
};

// 10,6,8,5,11,9
//  x

// stack: 11 10

// pop all smaller or equal
// push to queue

// popCount + !stk.empty()

// 3 1 2 1 1 0