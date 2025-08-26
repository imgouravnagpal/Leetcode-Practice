class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,sum = 0;
        unordered_map<int,int> m;
        for(int i:nums){
            sum += i;
            if(k == sum) ans++;
            ans += m[sum - k];
            m[sum]++;
        }
        return ans;
    }
};