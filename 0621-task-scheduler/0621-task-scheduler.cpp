class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> count;

        for (char c : tasks) {
            count[c] ++;
        }

        priority_queue<int> pq;
        queue<pair<int,int>> cooldown; // time, count
        int time = 0;

        for (auto& entry : count) {
            pq.push(entry.second);
        }

        while (!pq.empty() || !cooldown.empty()) {
            // pop all cooldown to heap
            // cout << "time " << time << endl;
            // cout << "size " << pq.size() << " " << cooldown.size() << endl;

            while (!cooldown.empty() && cooldown.front().first == time) {
                cout << cooldown.front().first << " " << cooldown.front().second << endl;
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            // no tasks to take, fast forward
            if (pq.empty()) {
                int newTime = cooldown.front().first;
                int newCount = cooldown.front().second;
                cooldown.pop();
                pq.push(newCount);
                time = newTime;
                // cout << "fast foward to " << newTime << endl;
            }

            // take one from max heap
            int taskCount = pq.top();
            pq.pop();
            // cout << "picked " << taskCount << endl;

            if (taskCount - 1 > 0) {
                cooldown.push({time + n + 1, taskCount - 1});
            }

            time ++;
        }

        return time;
    }
};

// count frequency with hashmap
// put count in maxHeap

// while heap not empty or queue not empty

// pop all cooldown to heap

// take one from max heap


