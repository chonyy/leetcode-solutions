class RLEIterator {
public:
    int size;
    vector<int> e;
    int i = 0;
    RLEIterator(vector<int>& encoding) {
        size = encoding.size();
        e = encoding;
    }
    
    int next(int n) {
        int prev = -1;
        while (n) {
            // if remain is more than n, remain -= n, n = 0
            // else n -= remain, i += 2
            // - if i >= size, return -1
            if (i >= size) {
                return -1;
            }

            if (e[i] == n) {
                prev = e[i+1];
                n = 0;
                i += 2;
            }
            else if (e[i] > n) {
                prev = e[i+1];
                e[i] -= n;
                n = 0;
            }
            else {
                n -= e[i];
                i += 2;
            }
        }

        return prev;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */