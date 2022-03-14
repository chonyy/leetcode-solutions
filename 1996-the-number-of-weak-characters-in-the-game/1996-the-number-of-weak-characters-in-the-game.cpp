class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if(v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }  
            return v1[0] < v2[0];
        };
        
        sort(properties.begin(), properties.end(), cmp);
        int n = properties.size();
        int maxDefense = properties[n-1][1];
        int weak = 0;
        
        for(int i = n-2; i >= 0; i --) {
            int def = properties[i][1];
            if(def < maxDefense) {
                weak ++;
            }
            else {
                maxDefense = def;
            }
        }
        
        return weak;
    }
};