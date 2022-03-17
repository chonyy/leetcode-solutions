class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        
        for(string& domain : cpdomains) {
            int i = 0;
            int n = domain.size();
            while(i < n) {
                if(domain[i] == ' ') {
                    break;
                }
                i ++;
            }
            
            int freq = stoi(domain.substr(0, i));
            i ++;
            count[domain.substr(i)] += freq;
            while(i < n) {
                if(domain[i] == '.') {
                    count[domain.substr(i+1)] += freq;
                }
                i ++;
            }
        }
        
        vector<string> res;
        for(auto& entry : count) {
            string r = to_string(entry.second) + " " + entry.first;
            res.push_back(r);
        }
        
        return res;
    }
};