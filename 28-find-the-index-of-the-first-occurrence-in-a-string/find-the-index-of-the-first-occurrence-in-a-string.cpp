class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        int n = haystack.size();
        int m = needle.size();
        
        int temp = 0;
        int ind= 0;
        int cnt = 0;
        if(n < m) return -1;
        while(temp <= n - m){
            if(haystack.substr(temp,m) == needle) {
                ind = temp;
                cnt++;
                break;
            };
            temp++;
        }
        if(cnt == 0) return -1;
        else return temp;
    }
};