class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;

        for (int i = 0; i < s.length(); ++i) {
            if (spaceSet.count(i)) { 
                result += " ";
            }
            result += s[i]; 
        }

        return result;

    }
};
