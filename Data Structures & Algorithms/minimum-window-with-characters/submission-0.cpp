class Solution {
public:
    string minWindow(string s, string t) {
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;
        unordered_map<char, int> hash;

        for(char ch : t){
            hash[ch]++;
        }

        int i = 0;
        for(int j=0; j<s.size(); j++){
            if(hash[s[j]] > 0) count++;
            hash[s[j]]--;

            while(count == t.size()){
                if(j-i+1 < minLength){
                    minLength = j-i+1;
                    startIndex = i;
                }
                hash[s[i]]++;
                if(hash[s[i]] > 0)  count--;
                i++;
            }
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
