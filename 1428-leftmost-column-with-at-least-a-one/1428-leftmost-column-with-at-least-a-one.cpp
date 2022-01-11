/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];
        
        int row = 0;
        int col = cols -1;
        int res = -1;
        while(col >= 0 && row < rows) {
            if(binaryMatrix.get(row, col)) {
                res = col;
                col --;
            }
            else {
                row ++;
            }
        }
            
        return res;
    }
};