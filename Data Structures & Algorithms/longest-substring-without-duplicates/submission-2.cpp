class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(size == 0)   return 0;

        int maxLength = 0;
        
        set<char> uniqueChars;
        int i = 0, j = 0;
        while(j < size){
            if(uniqueChars.find(s[j]) == uniqueChars.end()){
                uniqueChars.insert(s[j]);
                j++;
            }
            else{
                while(uniqueChars.find(s[j]) != uniqueChars.end()){
                    uniqueChars.erase(s[i]);
                    i++;
                }
            }
            maxLength = max(maxLength, j-i);
        }

        return maxLength;
    }
};
