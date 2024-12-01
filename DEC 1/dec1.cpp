class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;                //using a set for fast insertion and searching
        for(int i =0; i < arr.size(); i++){
            if(s.find(arr[i]*2) != s.end() || (arr[i]%2==0 ? s.find(arr[i]/2) != s.end() : false )) return true;         //checking for ele *2 and ele / 2 if ele is even
            s.insert(arr[i]);
        }
        return false;
    }
};
