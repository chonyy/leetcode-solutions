class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; i --) {
            int j = i + 1;
            // cout << "start " << i << endl;
            while (j < n && temperatures[j] <= temperatures[i]) { // keep looking for larger
                if (res[j] == 0) {
                    j = n;
                    break;
                }

                // cout << j << "add " << res[j] << endl;
                j += res[j];
            }

            if (j < n) {
                // cout << "set" << endl;
                res[i] = j - i;
            }
        }

        return res;
    }
};