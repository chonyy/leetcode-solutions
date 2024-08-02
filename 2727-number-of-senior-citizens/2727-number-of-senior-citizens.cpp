class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for(auto& d : details) {
            int age = stoi(d.substr(11,2));
            if(age > 60)
                res ++;
        }
        
        return res;
    }
};