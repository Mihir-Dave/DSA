class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        //int cnt = 0;
        int max_cnt = INT_MIN;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            mp[s[right]]++;
            //cnt++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            max_cnt = max(max_cnt,right-left+1);
        }
        return max_cnt;
    }
};