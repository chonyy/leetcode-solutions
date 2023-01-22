class Solution {
public:
    bool hasLeadingZero(string& s) {
        if(s == "0") {
            return false;
        }
        
        bool seenNumber = false;
        for(char c : s) {
            if(seenNumber == false)
                seenNumber = c != '0';
            
            if(!seenNumber && c == '0')
                return true;
        }
        
        return false;
    }
    
    void backtrack(vector<string>& res, string& s, int sIdx, vector<string>& ips, int ipIdx) {
        if(ipIdx >= 4) {
            if(sIdx == s.size()) {
                res.push_back(ips[0] + "." + ips[1] + "." + ips[2] + "." + ips[3]);
            }
            return;
        }
        
        for(int i = 1; i <= 3; i ++) {
            if(sIdx + (i-1) >= s.size()) {
                continue;
            }
            
            string candidateIp = s.substr(sIdx, i);
            if(hasLeadingZero(candidateIp)) {
                continue;
            }
            
            int ip = stoi(candidateIp);
            if(ip >= 0 && ip <= 255) {
                ips.push_back(candidateIp);
                backtrack(res, s, sIdx+i, ips, ipIdx+1);
                ips.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ips;
        
        backtrack(res, s, 0, ips, 0);
        
        return res;
    }
};