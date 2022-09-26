class Solution {
public:
    char findParent(char node, unordered_map<char, char>& parent) {
        if(parent[node] != node)
            return parent[node] = findParent(parent[node], parent);
        return node;
    }
    
    void unionn(char a, char b, unordered_map<char, char>& parent){
        char pa = findParent(a, parent);
        char pb = findParent(b, parent);
    
        if(pa != pb)
            parent[pa] = pb;
    }
    
    void buildGraph(vector<string>& equations, unordered_map<char, char>& parent) {
        for(auto e : equations) {
            if(e[1] == '=')
                unionn(e[0], e[3], parent);
        }
    }
    
    
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> parent;
        
        for(char c = 'a'; c <= 'z'; c ++){
            parent[c] = c;
        }
        
        buildGraph(equations, parent);
        
        for(auto e : equations) {
            if(e[1] == '!') {
                // cout << findParent(e[0], parent) << endl;
                // cout << findParent(e[3], parent) << endl;
                if(findParent(e[0], parent) == findParent(e[3], parent))
                    return false;
            }
        }
        
        return true;
    }
};