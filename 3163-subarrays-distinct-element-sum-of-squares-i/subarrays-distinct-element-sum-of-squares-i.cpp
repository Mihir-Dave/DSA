class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt = 0; 
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            
            cnt = 0;
            for(int j = i ; j < n ; j++){
                mp[nums[j]]++;
                
                cnt = mp.size();
                
                ans += (cnt*cnt);
            }
            mp.clear();
            
        }
        return ans;
    }
};