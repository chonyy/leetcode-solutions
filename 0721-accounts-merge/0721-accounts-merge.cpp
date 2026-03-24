class Solution {
public:
    unordered_map<string,string> parent;
    unordered_map<string,int> rank;
    unordered_map<string, set<string>> unions;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> emailToName;
        
        // Init disjoint set
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i ++) {
                string& email = account[i];
                emailToName[email] = name;
                parent[email] = email;
                rank[email] = 1;
            }
        }

        // Union all emails
        for (auto& account : accounts) {
            for (int i = 2; i < account.size(); i ++) {
                unionNode(account[i], account[i-1]);
            }
        }

        // Collect unions with parent. Note that the parent is one of the email, so no problem with duplicated names
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i ++) {
                string parent = find(account[i]);
                unions[parent].insert(account[i]);
            }
        }

        // Get res from unions
        vector<vector<string>> res;
        for (auto& entry : unions) {
            string& name = emailToName[entry.first];
            vector<string> temp = {name};

            for (auto& email : entry.second) {
                temp.push_back(email);
            }
            res.push_back(temp);
        }

        return res;
    }

    bool unionNode(string& n1, string& n2) {
        string p1 = find(n1);
        string p2 = find(n2);

        if (p1 == p2) {
            return false;
        }

        int r1 = rank[p1];
        int r2 = rank[p2];

        if (r1 >= r2) {
            parent[p2] = p1;
            rank[p2] ++;
        }
        else {
            parent[p1] = p2;
            rank[p1] ++;
        }

        return true;
    }

    string find(string& email) {
        if (parent[email] == email) {
            return email;
        }

        return parent[email] = find(parent[email]);
    }
};

// ["John","johnsmith@mail.com","john_newyork@mail.com"]
// ["John","johnsmith@mail.com","john00@mail.com"]
// ["Mary","mary@mail.com"]
// ["John","johnnybravo@mail.com"]