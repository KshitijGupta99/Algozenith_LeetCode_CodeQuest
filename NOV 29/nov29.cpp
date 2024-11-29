class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> s;
        unordered_map<int, int> h;
        for (int i = n2.size() -1; i >= 0; i--){
            while (!s.empty() && s.top() <= n2[i]) {
                s.pop();
            }
            int ele = n2[i];
            if (s.empty()) {
                h[n2[i]] = -1;
            } else {
                h[n2[i]] = s.top();
            }
            s.push(ele);
            cout << s.top() << "<--";
        }
        vector<int> res;
        for(int i = 0; i < n1.size(); i++){
            // cout << h[n2[i]];
            res.push_back(h[n1[i]]);
        }
        return res;
    }
    
};
