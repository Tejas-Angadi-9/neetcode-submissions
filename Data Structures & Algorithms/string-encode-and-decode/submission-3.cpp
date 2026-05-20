class Solution {
public:
    string encode(vector<string>& strs) {
        string encodedString = "";

        for(string str : strs){
            string length = to_string(str.length());
            encodedString += length + "#" + str;
        }
        return encodedString;
    }

    vector<string> decode(string str) {
        vector<string> ans;
        int i = 0;
        while(i < str.length()){
            int j = i;
            while(str[j] != '#'){
                j++;
            }
            int length = stoi(str.substr(i, j - i));
            i = j + 1;
            string word = str.substr(i, length);
            ans.push_back(word);
            i += length;
            j = i;
        }
        return ans;
    }
};





