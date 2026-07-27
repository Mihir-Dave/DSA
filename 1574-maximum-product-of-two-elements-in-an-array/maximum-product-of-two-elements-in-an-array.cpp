class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = INT_MIN, y = INT_MIN , ans,ind;
        for(int i = 0; i< nums.size() ; i++){
            if(nums[i] > x){
                x = nums[i];
                ind = i;
            }  
        }
        for(int i = 0; i< nums.size() ; i++){
            if(i == ind){
                continue;
            }
            if(nums[i] > y){
                y = nums[i];
                //ind = i;
            }
        }
        return (x-1)*(y-1);
    }
};