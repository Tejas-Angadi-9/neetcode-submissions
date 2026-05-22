class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestLength = 0;
        int size = s.length();
        for(int i=0; i<size; i++){
            unordered_map<char, int> charFreq;
            int maxFreqCount = 0;
            for(int j=i; j<size; j++){
                charFreq[s[j]]++;
                maxFreqCount = max(maxFreqCount, charFreq[s[j]]);
                int windowSize = j - i + 1;
                int possibleReplacables = windowSize - maxFreqCount;
                if(possibleReplacables <= k){ // This means we have enough chars that can be replaced
                    longestLength = max(longestLength, windowSize);
                }
            }
        }
        return longestLength;
    }
};
