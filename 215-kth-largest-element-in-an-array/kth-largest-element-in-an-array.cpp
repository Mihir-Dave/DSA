class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int cnt = 0;
        for(auto &num : nums){
            pq.push(num);
            cnt++;
            if(cnt > k){
                pq.pop();
                cnt--;
            }
        }
        return pq.top();
    }
};