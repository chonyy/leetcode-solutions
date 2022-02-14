class Solution {
public:
    int rows;
int cols;

int getArea(vector<vector<int>>& grid, int row, int col) {
	if(row < 0 || row >= rows || col < 0 || col >= cols)
		return 0;

	if(grid[row][col] == 0)
		return 0;

	grid[row][col] = 0;
	int area = 0;
	area += getArea(grid, row+1, col);
	area += getArea(grid, row-1, col);
	area += getArea(grid, row, col+1);
	area += getArea(grid, row, col-1);
	return area + 1;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
int ans = 0;        

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
		if(grid[i][j] == 0) 
			continue;
	ans = max(ans, getArea(grid, i, j));
}
        }

	return ans;
   }

};