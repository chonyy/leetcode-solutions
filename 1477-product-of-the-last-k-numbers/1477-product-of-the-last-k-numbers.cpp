class ProductOfNumbers {
public:
    vector<int> nums = {1};

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) {
            nums = {1};
        }
        else {
            nums.push_back(num * nums.back());
        }
    }
    
    int getProduct(int k) {
        if(k >= nums.size()) {
            return 0;
        }
        
        return nums.back() / nums[nums.size() - k - 1];
    }

    void printNum() {
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */