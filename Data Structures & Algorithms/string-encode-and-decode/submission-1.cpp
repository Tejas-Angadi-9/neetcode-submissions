class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        // Traverse the string array and get each string
        for(string str:strs){
            // Calculate the string length and before the start of each string append it's length in string also append a char ie. #
            int length = str.length();
            output += to_string(length) + '#' + str;
        }
        return output;
        // Then concat the entire strings into one and return it
    }

    vector<string> decode(string s) {
        vector<string> ans;
        // In this, we will use 2 pointers. i and j = 0
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j+1, length);
            ans.push_back(str);
            // At the end shift the pointers. -> YOU WILL FORGET THIS
            i = j+1+length;
        }
        // Move j until it is not #
        // Then just previous we know we have entered the length of the string
        // Then store the string's substring after the # till the length of the string
        return ans;
    }
};
