class Solution {
public:
    map<int, string, greater<>> d = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
        {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
        {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"},
        {1000000, "Million"}, {1000000000, "Billion"}
    };
    string numberToWords(int num) {
        string res = "";
        // cout << "get num " << num << endl;

        if (num == 100) {
            return "One Hundred";
        }

        for (auto& entry : d) {
            if (entry.first != 100 && entry.first != 1000 && entry.first != 1000000 && entry.first != 1000000000 && entry.first == num) {
                res += entry.second;
                break;
            }
            else if (entry.first != 0 && num / entry.first > 0) {
                int multi = num / entry.first;
                int remain = num % entry.first;

                if (entry.first >= 100) {
                    res += numberToWords(multi) + " ";
                }
                res += entry.second;
                if (remain > 0) {
                    res += " " + numberToWords(remain);
                }
                break; 
            }
        }

        return res;
    }
};


