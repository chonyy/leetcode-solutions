class Solution {
private:
    bool isUnique(string str) {
        if (str.size() > 26) return false;
        vector<bool> used(26, false);
        for (const auto & ch : str) {
            if (used[ch-'a']) return false;
            used[ch -'a'] = true;
        }
        return true;
}
public:
    int maxLength(vector<string>& arr) {
        vector<string> res{""};
        for (const auto & a : arr)    {
            if (!isUnique(a)) continue;
            vector<string> genList;
            for (auto & r : res) {
                string gen = a + r;
                if (isUnique(gen)) genList.push_back(gen);
            }
            res.insert(res.end(), genList.begin(),genList.end());
        }
        int ans = 0;
        for (const auto & str : res) ans = max(ans + 0UL, str.size());
        return ans;
    }
};