class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size() != t.size())    return false;

        // Create an array of size 26 with 0 as initial values
        vector<int> freq(26, 0);
        // Start iterating both the arrays but with single iteration
        for(int i = 0; i<s.length(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Iterate the freq array and check if any value is != 0, then return false
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] != 0)
                return false;
        }
        return true; 
    }
};
