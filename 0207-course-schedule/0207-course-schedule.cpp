class Solution {
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            // Cycle detected
            return false;
        }
        if (!preMap.contains(crs)) {
            return true;
        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(crs);
        preMap.erase(crs);
        return true;
    }
};