class Solution {
public:
    unordered_map<int, vector<string>> mem;
    vector<string> expand(string s) {
        vector<string> res = dfs(s, 0);
        sort(res.begin(), res.end());
        return res;
    }

    vector<string> dfs(string& s, int i) {
        if (i == s.size()) {
            return {""};
        }

        if (mem.contains(i)) {
            return mem[i];
        }

        int idx = i;
        vector<char> chars;

        // get cur strings
        if (s[idx] != '{') {
            chars.push_back(s[idx]);
        }
        else {
            idx ++;
            while (s[idx] != '}') {
                chars.push_back(s[idx]);
                idx ++;
                if (s[idx] == ',') {
                    idx ++;
                }
            }
        }

        // get suffixes from dfs
        vector<string> suffixes = dfs(s, idx + 1);

        // concactenate
        vector<string> res;

        for (char c : chars) {
            for (string& suf : suffixes) {
                string newS = c + suf;
                res.push_back(newS);
            }
        }

        mem[i] = res;
        return res;
    }
};

// dfs(s, index) => vector<string>

// if index == s.size()
//     return empty list


// if not braces
//     add char to returnList
//     early return


// find all char in current braces
// find suffxes from dfs

// res = []

// for c in char:
//     for suffix in suffixes:
//         res.append(c + suffix)

// cache
// return res