class Solution {
public:
    int findComplement(int num) {
        int bit = 1;
        int todo = num;
        
        while(todo != 0) {
            num = num ^ bit;
            
            todo = todo >> 1;
            bit = bit << 1;
        }
        
        return num;
    }
};