class SegNode {
  public:
    int val;
    int l;
    int r;
    SegNode* left;
    SegNode* right;
    
    SegNode(int val, int l, int r) {
        this->val = val;
        this->l = l;
        this->r = r;
    }
};

class SegmentTree {
    public:
        SegNode* root;
        
        SegmentTree() {
            
        }
    
        SegmentTree(int l, int r, vector<int>& nums) {
            root = buildTree(l, r, nums);
        }
    
        SegNode* buildTree(int l, int r, vector<int>& nums) {
            if(l == r) {
                return new SegNode(nums[l], l, r);
            }
            
            int mid = l + (r - l) / 2;
            auto left = buildTree(l, mid, nums);
            auto right = buildTree(mid+1, r, nums);
            
            int sum = left->val + right->val;
            auto root = new SegNode(sum, l, r);
            root->left = left;
            root->right = right;
            
            return root;
        }
    
        void update(int idx, int val) {
            _update(root, idx, val);
        }
    
        void _update(SegNode* root, int idx, int val) {
            if(idx == root->l&& idx == root->r) {
                root->val = val;
                return;
            }
            
            int mid = (root->l + root->r) / 2;
            
            if(idx <= mid) {
                _update(root->left, idx, val);
            }
            else {
                _update(root->right, idx, val);
            }
            
            root->val = root->left->val + root->right->val;
        }
    
        int query(int l, int r) {
            return _query(root, l, r);
        }
    
        int _query(SegNode* root, int l, int r) {
            if(l == root->l && r == root->r) {
                return root->val;
            }
            
            int mid = (root->l + root->r) / 2;
            
            if(r <= mid) {
                return _query(root->left, l, r);
            }
            else if(mid < l) {
                return _query(root->right, l, r);
            }
            
            int left = _query(root->left, l, mid);
            int right = _query(root->right, mid+1, r);
            
            return left + right;
        }
};

class NumArray {
public:
    SegmentTree st;
    
    NumArray(vector<int>& nums) {
        st = SegmentTree(0, nums.size()-1, nums);
    }
    
    void update(int index, int val) {
        st.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */