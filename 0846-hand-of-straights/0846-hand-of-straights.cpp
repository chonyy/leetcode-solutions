class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int,int> count;
        for (int num : hand) {
            count[num] ++;
        }

        for (int num : hand) {
            if (count[num] == 0) {
                continue;
            }

            while (count[num]) {
                int smallest = num;
                while (count[smallest-1]) {
                    smallest --;
                }

                // cout << "small " << smallest << endl;
                // try to get groupSize consecutive and update count
                for (int i = 0; i < groupSize; i ++) {
                    int target = smallest + i;

                    // cout << "target " << target << endl;
                    // cout << count[target] << endl;
                    if (count[target] == 0) {
                        return false;
                    }
                    count[target] --;
                }
            }
        }

        return true;
    }
};