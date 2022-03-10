class Solution {
public:
    // 2 3 5 7 
    // 2 2 3 
    vector<int> availables;
    int ava;
    Solution(int n, vector<int>& blacklist) {
        ava = n - blacklist.size();
        blacklist.push_back(n);
        int size = blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        
        for(int i = 0; i < size; i ++) {
            if(i == 0) {
                availables.push_back(blacklist[0]);
                continue;
            }
            availables.push_back(blacklist[i] - blacklist[i-1] - 1 + availables[i-1]);
            // cout << availables[i] << endl;
        }
    }
    
    int pick() {
        int r = rand() % ava;
        auto it = upper_bound(availables.begin(), availables.end(), r);
        return it - availables.begin() + r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */