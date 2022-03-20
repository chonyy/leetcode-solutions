class Solution {
public:
    int solve(int idx, int used, string& floor, int numCarpets, int carpetLen, vector<int>& whites, vector<vector<int>>& mem) {
        if(idx >= floor.size()) {
            return 0;
        }
        
        if(used == numCarpets) {
            return whites[idx];
        }
        
        if(mem[idx][used] != -1) {
            return mem[idx][used];
        }
        
        int cover = solve(idx+carpetLen, used+1, floor, numCarpets, carpetLen, whites, mem);
        int noCover = (floor[idx] == '1') + solve(idx+1, used, floor, numCarpets, carpetLen, whites, mem);
        
        return mem[idx][used] = min(cover, noCover);
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<int> whites(n, 0);
        vector<vector<int>> mem(n, vector<int>(numCarpets, -1));
        
        whites[n-1] = floor[n-1] == '1';
        for(int i = n-2; i >= 0 ; i --) {
            whites[i] = (floor[i] == '1') + whites[i+1];
        }
        
        return solve(0, 0, floor, numCarpets, carpetLen, whites, mem);
    }
};