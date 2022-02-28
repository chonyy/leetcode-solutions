class BrowserHistory {
public:
    vector<string> history;
    int cur = 0;
    
    void print() {
        cout << cur << endl;
        for(string& h : history) {
            cout << h << " ";
        }
        cout << endl;
    }
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        int toPop = history.size() - cur - 1;
        for(int i = 0; i < toPop; i ++) {
            history.pop_back();
        }
        
        history.push_back(url);
        cur = history.size() - 1; 
        // print();
    }
    
    string back(int steps) {
        int backSteps = max(0, cur - steps);
        cur = backSteps;
        // print();
        return history[cur];
    }
    
    string forward(int steps) {
        int forwardSteps = min(int(history.size() - 1), cur + steps);
        cur = forwardSteps;
        // print();
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// leetcode google facebook linkedin
//                     x