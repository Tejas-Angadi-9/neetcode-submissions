class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            output += to_string(str.size()) + "#" + str;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        
        return result;
    }
};
