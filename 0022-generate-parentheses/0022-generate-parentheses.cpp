class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> res;

        backtrack(res, temp, n, 0);

        return res;
    }

    void backtrack(vector<string>& res, string temp, int open, int close) {
        // terminal condition
        if (open == 0 && close == 0) {
            res.push_back(temp);
            return;
        }

        // try open and close

        if (open) {
            temp += '(';
            backtrack(res, temp, open-1, close+1);
            temp.pop_back();
        }

        if (close) {
            temp += ')';
            backtrack(res, temp, open, close-1);
            temp.pop_back();
        }
    }
};

// choose to open or close


// .

// open = 3
// close = 0

// (     

// open = 2
// close = 1


// ().                  ((

// open = 2            open = 1
// close = 0           close = 2


// if (close == 0 && open == 0) {
//     return ans;
// }

// if (open)
//     add open
//     backtrack
//     remove open

// if (close)
//     add close
//     backtrack
//     remove close