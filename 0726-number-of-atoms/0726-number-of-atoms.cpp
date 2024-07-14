class Solution {
public:
    int getNum(string& formula, int& i) {
        int num = 0;
        int n = formula.size();
        while(i < n && isdigit(formula[i])) {
            num = num * 10 + formula[i] - '0';
            i ++;
        }
        if(num == 0)
            num = 1;
        return num;
    }
    
    string countOfAtoms(string formula) {
        map<string,int> m;
        stack<map<string, int>> stk;
        int n = formula.size();
        int i = 0;
        
        while(i < n) {
            char c = formula[i];
            if(c == '(') {
                stk.push(m);
                m = {};
                i ++;
            }
            else if(c == ')') {
                auto temp = stk.top();
                stk.pop();
                i ++;
                
                // get num
                int num = getNum(formula, i);
                
                // update
                for(auto& entry : m) {
                    temp[entry.first] += entry.second * num;
                }
                swap(temp, m);
            }
            else { // base case
                // get element
                string ele = "";
                ele += c;
                i ++;
                while(i < n && islower(formula[i])) {
                    ele += formula[i];
                    i ++;
                }
                
                // get count
                int num = getNum(formula, i);
                m[ele] += num;
            }
        }
        
        string res = "";
        for(auto& entry : m) {
            res += entry.first;
            if(entry.second > 1) {
                res += to_string(entry.second);
            }
        }
        
        return res;
    }
};