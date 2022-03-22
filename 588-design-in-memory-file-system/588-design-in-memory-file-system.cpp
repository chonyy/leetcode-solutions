class FileNode {
    public:
        bool isFile;
        // auto cmp = [](FileNode* n1, FileNode* n2) {
        //     return n1->content < n2->content;
        // };
    
        map<string, FileNode*> children;
        string content;
    
        FileNode() {
            isFile = false;
            content = "";
        }
};

class FileSystem {
public:
    FileNode* root;
    
    FileSystem() {
        root = new FileNode();
    }
    
    vector<string> split(string& str, char del) {
        stringstream ss(str);
        vector<string> res;
        string temp;
        
        while(getline(ss, temp, del)) {
            res.push_back(temp);
        }
        
        return res;
    }
    
    FileNode* find(string& path) {
        auto dirs = split(path, '/');
        FileNode* cur = root;
        
        for(auto& dir : dirs) {
            if(cur->children.count(dir) == 0) {
                cur->children[dir] = new FileNode();
            }
            cur = cur->children[dir];
        }
        
        return cur;
    }
    
    vector<string> ls(string path) {
        auto node = find(path);
        
        // is file
        if(node->isFile) {
            auto dirs = split(path, '/');
            return {dirs.back()};
        }
        
        vector<string> res;
        
        for(auto& entry : node->children) {
            res.push_back(entry.first);
        }
        
        return res;
    }
    
    void mkdir(string path) {
        find(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto node = find(filePath);
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto node = find(filePath);
        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */