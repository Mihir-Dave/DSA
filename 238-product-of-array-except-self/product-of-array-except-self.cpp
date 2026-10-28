class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int prod = 1;
        for(int i=0; i<n ; i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                prod *= nums[i];
            }
        }
        for(int i=0; i<n ; i++){
            if(cnt > 1){
                nums[i] = 0;
            }else if(cnt == 1){
                if(nums[i] == 0){
                    nums[i] = prod;
                }else{
                    nums[i] = 0;
                }
            }else{
                nums[i] = (prod/nums[i]);
            }
        }
        return nums;
    }
};