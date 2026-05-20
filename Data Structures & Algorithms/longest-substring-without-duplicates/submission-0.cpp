class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(size == 0)   return 0;

        int maxLength = 0;
        
        for(int i=0; i<size; i++){
            set<char> uniqueChars;
            for(int j=i; j<size; j++){
                if(uniqueChars.find(s[j]) != uniqueChars.end()){
                    break;
                }
                else{
                    uniqueChars.insert(s[j]);
                    maxLength = max(maxLength, j-i+1);
                }
            }
        }
        return maxLength;
    }
};
