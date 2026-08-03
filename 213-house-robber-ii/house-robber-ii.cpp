class Solution {
public:
    int help(vector<int>& nums){
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i = 2 ; i< n ; i++){
            int curr = max(prev2+nums[i],prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> temp1, temp2;
        
        for(int i = 0 ; i < n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(help(temp1),help(temp2));
    }
};