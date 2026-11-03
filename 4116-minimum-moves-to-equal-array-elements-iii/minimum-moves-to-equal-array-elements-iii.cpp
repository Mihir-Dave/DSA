class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max_ele = INT_MIN;
        int ans = 0;
        for(int i=0; i<n ; i++){
            max_ele = max(max_ele,nums[i]);
        }
        for(int i=0; i<n ; i++){
            if(nums[i] < max_ele){
                int val = max_ele - nums[i];
                ans += val;
            }
        }
        return ans;

    }
};