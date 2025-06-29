class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
 
        vector<vector<set<int>>> dp(n, vector<set<int>>(k+1));

          for (int u = 0; u < n; u++) {
            dp[u][0].insert(0);
        }

        for(int i =0;i<k;i++)
            {
                for(auto edge: edges)
                    {
                        int start = edge[0];
                        int end = edge[1];
                        int w = edge[2];
                        
                        for(auto W : dp[start][i])
                            {
                                   int newW = w + W;
                                    if(newW < t)
                                    {
                                        dp[end][i+1].insert(newW);
                                    }
                            }
                     
                    }
            }

        int ans =-1;

        for(int i=0;i<n;i++)
            {
                if(!dp[i][k].empty())
                ans = max(ans, *prev(dp[i][k].end()));
            }

        return ans;
        
    }
};