class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        unordered_set<string> begin, end;

        if (target == "0000") {
            return 0;
        }

        if (ends.contains(target) || ends.contains("0000")) {
            return -1;
        }

        begin.insert("0000");
        end.insert(target);
        visited.insert("0000");
        visited.insert(target);

        int step = 0;

        while(!begin.empty() && !end.empty()) {
            step ++;
            cout << step << endl;

            if (begin.size() > end.size()) {
                cout << "swap" << endl;
                swap(begin, end);
            }

            unordered_set<string> temp;
            for (auto word : begin) {
                vector<string> neighbors = getNeighbors(word);

                for (auto& nei : neighbors) {
                    // important to check target first
                    if (end.contains(nei)) {
                        return step;
                    }

                    if (visited.contains(nei) || ends.contains(nei)) {
                        continue;
                    }

                    cout << nei << endl;
                    visited.insert(nei);
                    temp.insert(nei);
                }
            }

            swap(temp, begin);
        }

        return -1;
    }

    vector<string> getNeighbors(string& s) {
        vector<string> neighbors;

        for (int i = 0; i < 4; i ++) {
            char digit = s[i];
            char upper = digit == '9' ? '0' : digit+1;
            char lower = digit == '0' ? '9' : digit-1;

            neighbors.push_back(s.substr(0, i) + upper + s.substr(i+1));
            neighbors.push_back(s.substr(0, i) + lower + s.substr(i+1));
        }

        return neighbors;
    }
};