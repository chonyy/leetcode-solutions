class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long orig = stoll(n);
        set<long long> candidates;

        // Candidate 1 & 2: 10...01 and 99...9
        candidates.insert((long long)pow(10, len) + 1);     // 10001 for len=4
        candidates.insert((long long)pow(10, len - 1) - 1); // 999 for len=4

        // Candidates 3, 4, 5: mirror first half as-is, +1, -1
        int halfIdx = (len + 1) / 2;
        long long half = stoll(n.substr(0, halfIdx));

        for (long long h : {half - 1, half, half + 1}) {
            string prefix = to_string(h);
            string suffix = prefix.substr(0, len / 2);
            reverse(suffix.begin(), suffix.end());
            string palindrome = prefix + suffix;
            candidates.insert(stoll(palindrome));
        }

        candidates.erase(orig); // can't be itself

        long long ans = 0, gap = LLONG_MAX;
        for (long long cand : candidates) {
            long long diff = abs(cand - orig);
            if (diff < gap || (diff == gap && cand < ans)) {
                gap = diff;
                ans = cand;
            }
        }

        return to_string(ans);
    }
};

/*

1. reverse half of string
2. if odd: add to least significant of remain + reverse
3. go to n-1 digits and all 9



// 1 2 3 4
// even: size / 2
// 1 2 3
// odd: size / 2 + 1


110

1239
*/