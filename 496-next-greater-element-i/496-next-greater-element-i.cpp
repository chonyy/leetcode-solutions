class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> map;
        
        for(int num : nums2) {
            while(!stk.empty() && num > stk.top()) {
                map[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        
        vector<int> res;
        for(int num : nums1) {
            if(map.count(num) == 0) {
                res.push_back(-1);
                continue;
            }
            res.push_back(map[num]);
        }
        
        return res;
    }
};