class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        
        for(int num : target) {
            sum += num;
            pq.push(num);
        }
        
        while(pq.top() != 1) {
            int big = pq.top();
            int diff = sum - big;
            pq.pop();
            
            if(diff == 1) {
                return true;
            }
            if(diff == 0) {
                return false;
            }
            
            int newNum = big % diff;
            sum = sum - big + newNum;
            
            if(newNum == 0 || newNum == big) {
                return false;
            }
            pq.push(newNum);
        }
        
        return true;
    }
};