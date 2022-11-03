class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> queue;
        unordered_set<string> seen;
        queue.push(start);
        seen.insert(start);
        
        int steps = 0;
        while (!queue.empty()) {
            int nodesInQueue = queue.size();
            
            for (int j = 0; j < nodesInQueue; j++) {
                string node = queue.front();
                queue.pop();

                if (node == end) {
                    return steps;
                }
                
                for (char c: "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string neighbor = node;
                        neighbor[i] = c;
                        if (!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            queue.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};