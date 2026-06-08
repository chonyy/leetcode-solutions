class ThroneInheritance {
public:
    unordered_map<string,vector<string>> relation;
    unordered_set<string> dead;
    string king;

    ThroneInheritance(string kingName) {
        king = kingName;    
    }
    
    void birth(string parentName, string childName) {
        relation[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(res, king);
        return res;
    }

    void dfs(vector<string>& res, string& cur) {
        if (!dead.contains(cur)) {
            res.push_back(cur);
        }

        if (relation[cur].empty()) {
            return;
        }

        for (string& child : relation[cur]) {
            dfs(res, child);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */