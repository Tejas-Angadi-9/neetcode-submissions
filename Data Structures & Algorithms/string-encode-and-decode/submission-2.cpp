class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs){
            int len = str.size();
            cout<<"Length: "<<len<<endl;
            string lens = std::to_string(len);
            ans.append(lens);
            ans.append("#");
            ans.append(str);
            // ans += lens + str + "#";
        }
        return ans;
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
