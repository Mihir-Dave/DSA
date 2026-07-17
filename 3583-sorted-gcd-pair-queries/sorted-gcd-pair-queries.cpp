class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        // pairs divisible by d
        vector<long long> exact(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
        }

        // inclusion exclusion
        for (int d = mx; d >= 1; d--) {
            for (int m = 2 * d; m <= mx; m += d) {
                exact[d] -= exact[m];
            }
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};