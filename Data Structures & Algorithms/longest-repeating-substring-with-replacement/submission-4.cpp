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
            while((j-i+1) - maxFreqCount > k){
                mpp[s[i]]--;
                maxFreqCount = max(maxFreqCount, mpp[s[i]]);
                i++;
            }
            longestLength = max(longestLength, j-i+1);
        }
        return longestLength;
    }
};
