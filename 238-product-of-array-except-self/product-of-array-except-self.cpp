class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                prod *= nums[i];
            }
        }
        if(cnt == 0){
            for(int i = 0 ; i<n ; i++){
                nums[i] = prod / nums[i];
            }
        }
        else if(cnt > 1){
            for(int i = 0 ; i<n ; i++){
                nums[i] = 0;
            }
        }else{
            for(int i = 0 ; i<n ; i++){
                if(nums[i] != 0){
                    nums[i] = 0;
                }else{
                    nums[i] = prod;
                }
            }
        }
        return nums;
    }
};