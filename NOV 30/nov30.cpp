class Solution {
public:
    bool isPalindrome(string str) {
        string s;
        for(int i= 0; i < str.size(); i++){
            char c = str[i];
            if(isalnum(c)) s+= tolower(c);
        }                                  //comnverting the str to lowercase alpha numeric
        int l = 0;
        int r = s.size() -1;
   
        while(l <= r){
            if(s[l] != s[r]){return false;}                     // checking for wrong char
            l++;
            r--;
        }
        return true;
    }
};
