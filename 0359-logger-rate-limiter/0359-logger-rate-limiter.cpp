class Logger {
public:
    unordered_map<string,int> seen;
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!seen.contains(message)) {
            seen[message] = timestamp + 10;
            return true;
        }

        if (timestamp < seen[message]) {
            return false;
        }

        seen[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */