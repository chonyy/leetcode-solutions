class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> valToIdx;

        int count = 1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == x) {
                // cout << count << " " << i << endl;
                valToIdx[count] = i;
                count ++;
            }
        }

        vector<int> res;
        for (int q : queries) {
            if (!valToIdx.contains(q)) {
                res.push_back(-1);
            }
            else {
                res.push_back(valToIdx[q]);
            }
        }

        return res;
    }
};