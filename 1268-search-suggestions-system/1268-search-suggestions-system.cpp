class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string cur = "";
        
        for(char c : searchWord) {
            cur += c;
            auto l = lower_bound(products.begin(), products.end(), cur);
            auto r = upper_bound(products.begin(), products.end(), cur + '~');
            
            vector<string> temp;
            
            for(int i = 0; i < 3; i ++) {
                if(l == r)
                    break;
                temp.push_back(*l);
                l = next(l);
            } 
            
            res.push_back(temp);
        }
        
        return res;
    }
};