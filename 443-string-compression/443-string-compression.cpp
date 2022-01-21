class Solution {
public:
    int appendCount(vector<char>& chars, int outputIdx, int count) {
        string str = to_string(count);
        int size = str.size();
        
        for(int i = 0; i < size; i ++) {
            chars[outputIdx+i] = str[i]; 
        }
        
        return outputIdx + size;
    }
    
    int compress(vector<char>& chars) {
        if(chars.size() == 1) {
            return 1;
        }
        int n = chars.size();
        int outputIdx = 1;
        int curIdx = 1;
        int curChar = chars[0];
        int count = 1;
        
        for(int i = 1; i < n; i ++) {
            char c = chars[i];
            if(c != curChar) {
                if(count > 1) {
                    outputIdx = appendCount(chars, outputIdx, count);
                }
                curChar = c;
                count = 1;
                
                chars[outputIdx] = curChar;
                outputIdx ++;
            }
            else {
                count ++;
            }
        }
        if(count > 1)
            outputIdx = appendCount(chars, outputIdx, count);
        
        return outputIdx;
    }
};

// if same char
//     increment count
// if different char
//     append count to ouput
//     reinit curChar and count
//     move outputIdx


// if single character
// return directly

// x
// a a b b c c c 

// outputIdx = 0
// curIdx = 0
// curChar = a
// outputStr = ""    
// count = 0

    
//   x
// a a b b c c c 

// outputIdx = 1
// curIdx = 1
// curChar = a
// outputStr = "a"    
// count = 2
    
//     x
// a a b b c c c 

// outputIdx = 2
// curIdx = 2
// curChar = c
// outputStr = "a2"    
// count = 1
    
    
    
    
    