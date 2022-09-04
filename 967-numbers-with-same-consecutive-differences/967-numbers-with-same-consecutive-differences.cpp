class Solution {
public:
    int n ,k;
    vector<int>a;
    void f(int sz,int val, int prev_digit){
        if(sz==n){
            a.push_back(val);
            return;
        }
        for(int i=0;i<=9;i++){
            if(abs(i-prev_digit)==k){
                f(sz+1,val*10+i,i);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n=n;this->k=k;
        for(int i=1;i<=9;i++){
           f(1,i,i);   
        }
        return a;
    }
};