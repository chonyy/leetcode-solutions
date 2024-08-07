class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;

        for(auto& str : arr) {
            count[str] ++;
        }
        
        for(auto& str : arr) {
            if(count[str] == 1) {
                k --;
                if(k == 0) {
                    return str;
                }
            }
        }

        return "";
    }
};