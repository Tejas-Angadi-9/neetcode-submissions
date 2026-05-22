class Solution {
public:
    int characterReplacement(string s, int k) {
        // Then assign 2 ptrs i = 0 and j = 0 as we will use this as sliding window
        // Run the loop until j is inside the string length
        // Create a hashmap and store the frequency of all the chars in this sliding window
        // If jth character is not equal to max frequency element
            // Then check if we have the k available, if yes then replace and move the j++. Calculate the size
            // If not then move the i++ and remove that character from the hashmap
        // Continue

        int longestLength = 0;
        int size = s.length();
        for(int i=0; i<size; i++){
            unordered_map<char, int> charFreq;
            int maxFreqCount = 0;
            for(int j=i; j<size; j++){
                charFreq[s[j]]++;
                maxFreqCount = max(maxFreqCount, charFreq[s[j]]);
                int windowSize = j - i + 1;
                int replaceableChars = windowSize - maxFreqCount;
                if(replaceableChars <= k){ // This means we have enough chars that can be replaced
                    longestLength = max(longestLength, windowSize);
                }
            }
        }
        return longestLength;
    }
};
