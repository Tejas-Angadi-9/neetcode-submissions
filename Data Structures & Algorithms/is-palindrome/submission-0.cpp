class Solution {
public:
    bool isAlphaNum(char ch){
        if(ch >= 'A' && ch <= 'Z' ||
           ch >= 'a' && ch <= 'z' ||
           ch >= '0' && ch <= '9')
        return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while(i < j){
            while(i < j && !isAlphaNum(s[i])) i++;
            while(j > i && !isAlphaNum(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }
        return true;
    }
};
