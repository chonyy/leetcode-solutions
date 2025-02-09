class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int,int> ballColor;
        unordered_map<int,int> colorBall;

        for(auto& q : queries) {
            int ball = q[0];
            int color = q[1];

            int originalColor = ballColor[ball];

            ballColor[ball] = color;
            colorBall[color] ++;
            colorBall[originalColor] --;

            if(colorBall[originalColor] <= 0) {
                colorBall.erase(originalColor);
            }

            res.push_back(colorBall.size());
        }

        return res;
    }
};