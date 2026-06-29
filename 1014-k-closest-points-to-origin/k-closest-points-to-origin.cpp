class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;

        for(auto &it : points){
            int dist =((it[0])*(it[0]))+((it[1])*(it[1]));
            pq.push({dist,it});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};