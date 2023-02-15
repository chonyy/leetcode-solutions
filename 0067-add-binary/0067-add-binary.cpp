class Solution {
public:
    string addBinary(string a, string b) {
    string ans = "";
    int n = a.size();
    int m = b.size();
    int i = n -1, j = m - 1;
    int carry = 0;
    while(i >= 0 || j >= 0) {
        int aNum = 0, bNum = 0;
        if(i >= 0) {
            aNum = a[i] - '0';
        }
        if(j >= 0) {
            bNum = b[j] - '0';
        }
        int sum = aNum + bNum + carry;
        carry = 0;
        // cout << "sum" << sum << endl;
        if(sum >= 2) {
            sum %= 2;
            carry = 1;
        }
        ans.insert(0, 1, sum + '0');
        i --;
        j --;
    }
    if(carry)
        ans.insert(0, 1, '1');
    return ans;
}

};