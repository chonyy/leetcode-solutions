class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty)
            return false;
        
        while(tx > sx && ty > sy) {
            if(tx > ty) {
                tx = tx % ty;
            }
            else {
                ty = ty % tx;
            }
        }
        
        if(tx != sx && ty != sy) {
            return false;
        }
        
        if(tx == sx) {
            int diff = ty - sy;
            return diff % tx == 0;
        }
        
        int diff = tx - sx;
        return diff % ty == 0;
    }
};