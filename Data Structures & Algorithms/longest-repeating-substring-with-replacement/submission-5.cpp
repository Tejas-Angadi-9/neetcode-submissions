class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestLength = 0;
        int size = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int maxFreqCount = 0;
        for(int j=0; j<size; j++){
            mpp[s[j]]++;
            maxFreqCount = max(maxFreqCount, mpp[s[j]]);
            int windowSize = j - i + 1;
            int replaceableCharCount = windowSize - maxFreqCount;
            while(replaceableCharCount > k){
                mpp[s[i]]--;
                i++;
                maxFreqCount = max(maxFreqCount, mpp[s[i]]);
                windowSize = j - i + 1;
                replaceableCharCount = windowSize - maxFreqCount;
            }
            longestLength = max(longestLength, windowSize);
        }
        return longestLength;
    }
};
