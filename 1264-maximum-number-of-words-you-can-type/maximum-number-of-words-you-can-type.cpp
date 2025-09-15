class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<int,int> mp;
        for(auto i : brokenLetters)
        {
            mp[i]++;
        }

        int cnt = 0;
        int i = 0;
        while(i < text.size())
        {
            bool broken_found = 0;
            while(i<text.size() && text[i] != ' ')
            {
                if(mp.find(text[i]) != mp.end())
                {
                    broken_found = 1;
                }
                i++;
            }

            if(!broken_found)
            {
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};