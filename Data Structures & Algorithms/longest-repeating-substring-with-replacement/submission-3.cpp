class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestLength = 0;
        int size = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int maxFreqCount = 0;
        while(j < size){
            mpp[s[j]]++;
            maxFreqCount = max(maxFreqCount, mpp[s[j]]);
            int windowSize = j - i + 1;
            int replaceableCharCount = windowSize - maxFreqCount;
            if(replaceableCharCount <= k){
                longestLength = max(longestLength, windowSize);
                j++;
            }
            while(i<=j && replaceableCharCount > k){
                mpp[s[i]]--;
                maxFreqCount = max(maxFreqCount, mpp[s[i]]);
                i++;
            }
        }
        return longestLength;
    }
};
