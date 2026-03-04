class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        for (int i = 0; i < (n / 2); i ++) {
            cout << i << " " << n - 1 - i << endl;
            swap(s[i], s[n - 1 - i]);
        }
    }
};