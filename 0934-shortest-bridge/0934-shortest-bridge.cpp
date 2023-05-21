class Solution
{
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>> &grid, int i, int j, deque<pair<int, int>> &q, vector<vector<int>> &visited)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;

        if (visited[i][j])
            return;

        if (grid[i][j] != 1)
            return;

        grid[i][j] = 2;
        q.push_front({i, j});
        visited[i][j] = 1;

        for (auto dir : dirs)
        {
            int row = i + dir[0];
            int col = j + dir[1];

            dfs(grid, row, col, q, visited);
        }
    }

    // Mark one of the island to 2
    void findFirstIsland(vector<vector<int>> &grid, deque<pair<int, int>> &q, vector<vector<int>> &visited)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, q, visited);
                    return;
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>> &A)
    {
        int steps = 0;
        deque<pair<int, int>> q;
        rows = A.size();
        cols = A[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // Find the first island, mark it as 2
        findFirstIsland(A, q, visited);

        // Perform BFS from the first island
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto cur = q.back();
                q.pop_back();
                if (A[cur.first][cur.second] == 1)
                    return steps-1;

                for (auto dir : dirs)
                {
                    int row = cur.first + dir[0];
                    int col = cur.second + dir[1];

                    // out of boundary
                    if (row < 0 || row >= rows || col < 0 || col >= cols)
                    {
                        continue;
                    }

                    // skip if visited
                    if (visited[row][col])
                    {
                        continue;
                    }

                    visited[row][col] = 1;
                    q.push_front({row, col});
                }
            }
            steps++;
        }

        // Found the shortest path if we reached a 1

        return steps;
    }
};

// 1 1 1 1 1
// 1 0 0 0 1
// 1 0 1 0 1
// 1 0 0 0 1
// 1 1 1 1 1