class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for(auto i :nums)
        {
            freq[i] ++;
        }
        
        for(auto i :nums)
        {
            if(freq[i] > 1)
            {
                return i;
            }
        }
        return 0;

}
};