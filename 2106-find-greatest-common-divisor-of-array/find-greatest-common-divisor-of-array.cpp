class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int n = nums.size();
        for(int i= 0; i <n ; i++){
            min_val = min(min_val,nums[i]);
            max_val = max(max_val,nums[i]);
        }
        return func(min_val,max_val);
    }
    int func(int a,int b){
        int ans = 1;
        int n = max(a,b);
        for(int i=1 ; i <= n ; i++){
            if(a % i == 0 && b %i  == 0){
                ans = i;
            }
        }
        return ans;
    }
};