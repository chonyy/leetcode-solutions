class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;
        pq.push(1);

        int i = 0;

        while(i <= n) {
            long long num = pq.top();
            pq.pop();

            if(seen.count(num)) {
                continue;
            }

            seen.insert(num);
            cout << num << endl;

            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);

            if(i == n-1)
                return num;

            i ++;
        }

        return -1;
        
    }
};