class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> count;
        
        for(char c : text) {
            count[c] ++;
        }
        
        string check = "balon";
        int minn = INT_MAX;
        
        for(char c : check) {
            if(c == 'l')
                minn = min(minn, count[c] / 2);
            else if(c == 'o')
                minn = min(minn, count[c] / 2);
            else
                minn = min(minn, count[c]);
        }
        
        return minn;
    }
};