class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int cnt = 1;
        int max_val = 1;
        for(int i = 1 ; i<n ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] == nums[i-1]+1){
                cnt++;
            }else{
                cnt = 1;
            }
            max_val = max(max_val,cnt);
        }
        return max_val;
    }
};