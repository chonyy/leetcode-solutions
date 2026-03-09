class Solution {
public:
    string simplifyPath(string path) {
        int idx = 0;
        vector<string> stk;

        while (idx < path.size()) {
            while (idx < path.size() && path[idx] == '/') {
                // cout << "skip " << path[idx] << endl;
                idx ++;
            }

            if (idx == path.size()) {
                break;
            }

            int start = idx;
            int len = 0;
            while (idx < path.size() && path[idx] != '/') {
                // cout << "take " << path[idx] << endl;
                len ++;
                idx ++;
            }

            string temp = path.substr(start, len);
            // cout << temp << endl;

            if (temp == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else if (temp == ".") {
                continue;
            } else {
                stk.push_back(temp);
            }
        }

        string res;

        for (int i = 0; i < stk.size(); i ++) {
            res += "/";
            res += stk[i];
        }

        return res.size() == 0 ? "/" : res;
    }
};