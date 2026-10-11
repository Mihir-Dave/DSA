class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int val = 0;
        int n = nums.size();
        if(n == 0) return val;
        for(int i=0; i<n ; i++){
            if(n % (i+1) == 0){
                //cout<<nums[i];
                val += (nums[i]*nums[i]);
            }
        }
        return val;
    }
};