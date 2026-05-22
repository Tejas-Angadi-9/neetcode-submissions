class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1. Create a count array of 26 size with 0
        // 2. Increment the count array value by 1 with the index of s string's each char
        // 3. Then decrement the count array's value by 1 with the index of t string's each char
        // 4. Iterate through the count array and if any value is > 0 then return false or at end return true
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
