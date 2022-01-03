class Solution {
public:
    int cal(int left, int right, string& op) {
        if(op == "*")
            return left * right;
        else
            return left / right;
        return 0;
    }
    
    vector<string> parse(string s) {
        vector<string> split;
        string temp = "";
        int n = s.size();
        
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(c == ' ') {
                continue;
            }
            if(!isdigit(c)) {
                split.push_back(temp);
                split.push_back(string(1,c));
                temp = "";
            }
            else {
                temp.push_back(c);
            }
        }
        
        if(temp.size())
            split.push_back(temp);
        
        return split;
    }
    
    int calculate(string s) {
        vector<string> tokens = parse(s);
        int res = 0;
        int prev = stoi(tokens[0]);
        
        for(int i = 1; i < tokens.size(); i ++) {
            string tok = tokens[i];
            if(tok == "*" || tok == "/") {
                int next = stoi(tokens[i+1]);
                i ++;
                int temp = cal(prev, next, tok); 
                prev = temp;
            }
            else if(tok == "+" || tok == "-") {
                int next = stoi(tokens[i+1]);
                i ++;
                if(tok == "-")
                    next *= -1;
                res += prev;
                prev = next;
            }
        }
        
        return res + prev;
    }
};

//   o
// 3 + 2 * 2 - 2

// res = 5
    
// last = -2
