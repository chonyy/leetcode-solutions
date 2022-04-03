class Encrypter {
public:
    unordered_map<char,string> mapping;
    unordered_map<string, int> count;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i = 0; i < n; i ++) {
            char c = keys[i];
            mapping[c] = values[i];
        }
        
        for(string& word : dictionary) {
            count[encrypt(word)] ++;
        }
    }
    
    string encrypt(string word1) {
        string res = "";
        for(char c : word1) {
            res += mapping[c];
        }
        
        return res;
    }
    
    int decrypt(string word2) {
        return count[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */