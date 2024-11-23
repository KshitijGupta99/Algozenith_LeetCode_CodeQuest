class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq (score.begin(), score.end());
        unordered_map<int, string> h;
        vector<string> res;
        
        h[pq.top()] = "Gold Medal";
        pq.pop();
        if(!pq.empty()){
            h[pq.top()] = "Silver Medal";
            pq.pop();
        }
        if(!pq.empty()){
            h[pq.top()] = "Bronze Medal";
            pq.pop();
        }
        int cnt = 4;
        while(pq.empty() == false){
            h[pq.top()] = to_string(cnt);
            pq.pop();

            cnt++;
        }
        
        for(int i = 0; i <score.size(); i++){
            cout << h[score[i]] << '\n';
            res.push_back(h[score[i]]);
        }
        return res;
    }
};
