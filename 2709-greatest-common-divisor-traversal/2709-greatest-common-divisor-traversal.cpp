class UnionFind {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    UnionFind(int n) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find (parent[node]);
    }

    bool unionNode(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return false;
        }

        int r1 = rank[p1];
        int r2 = rank[p2];

        if (r1 >= r2) {
            parent[p2] = p1;
            rank[p1] ++;
        }
        else {
            parent[p1] = p2;
            rank[p2] ++;
        }

        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf = UnionFind(n);
        unordered_map<int,int> factToNum;

        for (int i = 0; i < n; i ++) {
            // check factors till sqrt
            // if factor already exists, union(num, factToNum[fact])
            // else add to factToNum
            int num = nums[i];
            int end = sqrt(num);
            // cout << "num " << num << endl;

            for (int fact = 2; fact <= end; fact ++) {
                while (num % fact == 0) {
                    // cout << num << " % " << fact << endl;
                    if (factToNum.contains(fact)) {
                        // cout << "fact " << fact << endl;
                        uf.unionNode(i, factToNum[fact]);
                    }
                    else {
                        factToNum[fact] = i;
                    }
                    num = num / fact;
                }
            }

            if (num == 1) {
                continue;
            }

            // check remainder num
            if (factToNum.contains(num)) {
                uf.unionNode(i, factToNum[num]);
            }
            else {
                factToNum[num] = i;
            }
        }

        unordered_set<int> roots;

        for (int i = 0; i < n; i ++) {
            roots.insert(uf.find(i));
        }

        return roots.size() == 1;
    }
};