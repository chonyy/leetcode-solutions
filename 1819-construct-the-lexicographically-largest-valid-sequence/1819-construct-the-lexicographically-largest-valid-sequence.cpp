class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = n * 2 - 1;
        vector<int> cur(size);
        vector<int> res(size);
        unordered_set<int> used;
        
        construct(0, n, cur, used, res);

        return res;
    }

    bool construct(int idx, int num, vector<int>& cur, unordered_set<int>& used, vector<int>& res) {
        if(used.size() == num) {
            res = cur;
            return true;
        }

        if(cur[idx] != 0) {
            return construct(idx + 1, num, cur, used, res);
        }

        for(int i = num; i >= 1; i --) {
            if(used.count(i))
                continue;

            used.insert(i);

            if(i != 1 && idx + i < cur.size() && cur[idx] == 0 && cur[idx + i] == 0) {
                cur[idx] = i;
                cur[idx + i] = i;

                if(construct(idx + 1, num, cur, used, res))
                    return true;

                cur[idx] = 0;
                cur[idx + i] = 0; 
            }
            else if(i == 1 && cur[idx] == 0) {
                cur[idx] = 1;

                if(construct(idx + 1, num, cur, used, res))
                    return true;

                cur[idx] = 0;
            }

            used.erase(i);
        }

        return false;
    }

    void printCur(vector<int>& cur) {
        for(int num : cur) {
            cout << num << " ";
        }
        cout << endl;
    }
};