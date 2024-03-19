class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        // counting frequency
        for(char task : tasks) {
            m[task] ++;
        }

        // pushing the frequency to the maxHeap
        priority_queue<int> maxHeap;
        for(auto it = m.begin(); it != m.end(); it ++) {
            maxHeap.push(it->second);
        }

        int cycles = 0;
        while(!maxHeap.empty()) {
            vector<int> doing;
            for(int i = 0; i <= n; i ++) {
                // for each unit of time
                if(!maxHeap.empty()) {
                    doing.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            // push back the not done tasks
            for(int task : doing) {
                if(task - 1 > 0) {
                    maxHeap.push(task-1);
                }
            }

            if(maxHeap.size()) {
                cycles += n + 1;
            }
            else {
                cycles += doing.size();
            }
        }

        return cycles;
    }
};