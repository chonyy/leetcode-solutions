class Solution {
public:
    unordered_map<int, string> ones = {
        {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"},
        {6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"},
        {11,"Eleven"}, {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"},
        {15,"Fifteen"}, {16,"Sixteen"}, {17,"Seventeen"}, {18,"Eighteen"},
        {19,"Nineteen"}
    };

    unordered_map<int, string> tens = {
        {2,"Twenty"}, {3,"Thirty"}, {4,"Forty"}, {5,"Fifty"},
        {6,"Sixty"}, {7,"Seventy"}, {8,"Eighty"}, {9,"Ninety"}
    };

    vector<pair<int,string>> units = {
        {1000000000,"Billion"}, {1000000,"Million"}, {1000,"Thousand"}
    };

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";

        for (auto& [val, word] : units) {
            if (num >= val) {
                res += helper(num / val) + " " + word;
                num = num % val;
                if (num % val) {
                    res += " ";
                }
            }
        }
        
        if (num) {
            res += helper(num);
        }

        return res;
    }

    string helper(int num) {
        if (num == 0) return "";

        string res = "";

        if (num < 20) {
            res += ones[num];
        }
        else if (num >= 20 && num < 100) {
            res += tens[num / 10];
            if (num % 10) {
                res += " " + helper(num % 10);
            }
        }
        else {
            res += ones[num / 100] + " Hundred";
            if (num % 100) {
                res += " " + helper(num % 100);
            }
        }

        return res;
    }
};