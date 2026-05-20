class Solution {
public:
    bool isAnagram(string s, string t) {
        // Main edge case if both the string size doesn't match the return false
        // 1. Create a count array of 26 size with 0
        // 2. Increment the count array value by 1 with the index of s string's each char
        // 3. Then decrement the count array's value by 1 with the index of t string's each char
        // 4. Iterate through the count array and if any value is > 0 then return false or at end return true
        if(s.size() != t.size())    return false;  
        int count[26] = {0};

        for(auto it:s){
            count[it - 'a']++;
        }

        for(auto it:t){
            count[it-'a']--;
        }

        for(auto it:count){
            if(it > 0)
                return false;
        }
        return true;
    }
};
