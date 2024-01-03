class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int sum = 0;
        
        for(auto &s : bank) {
            int sec = 0;
            for(char c : s) {
                sec += c == '1';
            }
            
            
            sum += sec * prev;
            if(sec) {
                prev = sec;
            }
        }
        
        return sum;
    }
};