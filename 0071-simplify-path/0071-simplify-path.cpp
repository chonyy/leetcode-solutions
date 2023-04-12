class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        vector<string> dirs;
        string res = "";
        
        while(getline(ss, temp, '/')) {
            if(temp == ".")
                continue;
            if(temp == "..") {
                if(dirs.size() > 0)
                    dirs.pop_back();
                continue;
            }
            if(temp.size() == 0)
                continue;
            dirs.push_back(temp);
        }
        
        for(string& dir : dirs) {
            res += "/" + dir;
        }
        
        return res.size() > 0 ? res : "/";
    }
};