class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> is = find(s, a);
        vector<int> js = find(s, b);

        // for (int i : is) {
        //     cout << i << " ";
        // }
        // cout << endl;

        vector<int> res;

        for (int i : is) {
            int target = i - k;
            auto it = lower_bound(js.begin(), js.end(), target);

            if (it == js.end()) {
                continue;
            }

            int diff = abs(*it - i);
            if (diff <= k) {
                res.push_back(i);
            }
        }

        return res;
    }

    vector<int> find(string& haystack, string& needle) {
        vector<int> res;
        int m = needle.size();
        vector<int> lps(m);

        int i = 1;
        int j = 0;
        while (i < m) {
            if (needle[i] == needle[j]) {
                j ++;
                lps[i] = j;
                i ++;
            }
            else {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    lps[i] = 0;
                    i ++;
                }
            }
        }

        int n = haystack.size();
        i = 0;
        j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i ++;
                j ++;
            }
            else {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i ++;
                }
            }

            if (j == m) {
                res.push_back(i - j);
                j = lps[j-1];
            }
        }

        return res;
    }
};


// i: 15 20 23
// j: 10, 18
// k: 10
