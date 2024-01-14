class Solution {
public:
   bool closeStrings(string word1, string word2) {
       // condition1 : we need the size of both strings to be same
       // condition2 : we need freq of char in strings to be same, irrespective of the order
       // if above 2 conditions are satisfied then just swapping will get us the word2 from word1
       
       if(word1.size()!=word2.size())
           return false;
       
       set<char> s1, s2;
       vector<int> freq1(26,0), freq2(26,0);
       
       for(int i=0; i<word1.size(); i++)
       {
           s1.insert(word1[i]);
           s2.insert(word2[i]);
           
           freq1[word1[i] - 'a']++;
           freq2[word2[i] - 'a']++;
       }
       
       sort(freq1.begin(), freq1.end());
       sort(freq2.begin(), freq2.end());
       
       if(s1==s2 && freq1==freq2)
           return true;
       else
           return false;       
   }
};