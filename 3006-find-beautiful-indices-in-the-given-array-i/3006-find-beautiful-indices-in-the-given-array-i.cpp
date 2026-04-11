class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> is = find(s, a);
        vector<int> js = find(s, b);

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
        int n = haystack.size();
        int i = 0;

        while (i < n) {
            int j = 0;
            while (j < needle.size() && haystack[i+j] == needle[j]) {
                j ++;
            }

            if (j == needle.size()) {
                res.push_back(i);
            }
            i ++;
        }

        return res;
    }
};


// i: 15 20 23
// j: 10, 18
// k: 10
