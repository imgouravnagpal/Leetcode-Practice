// we will simply maintain a 2d array which shows that if the string is palindrome from i to j with the length j-i+1 .. 
// we will move diagonally in the matrix like firstly we will work for strings with size 1 then size 2 and so on 
// like we picked up i =0 and j=4 then the string will be from 0 index to 4th index .. we will check if s[0] == s[4] 
// if yes we will check for dp ans at i+1 and j-1 if it is also a palindromic substring we will compare it by our final ans
//  if the length is larger than final ans then we will simply replace the final ans....    



class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int size = s.size();
        int start=1;
        int end=0;
        vector<vector<int>>dp(size,vector<int>(size,-1));
        
        for(int k=0;k<size;k++)
        {
            for(int i=0,j=i+k;i<size &&j<size;i++,j++)
            {
               
                    if(i == j)
                    {
                        dp[i][j] = 1;
                        if(end-start+1 < j-i+1)
                        {
                            start = i;
                            end = j;
                        }
                        continue;
                    }
                    if(s[i] != s[j]){
                        continue;
                    }
                    
                    if(j-i == 1)
                    {
                        if(end-start+1 < j-i+1)
                        {
                            start = i;
                            end = j;
                        }
                        dp[i][j] = 1;
                        continue;
                    }
                    
                    if(dp[i+1][j-1] != -1)
                    {
                        if(end-start+1 < j-i+1)
                        {
                            start = i;
                            end = j;
                        }
                        dp[i][j] = dp[i+1][j-1] +1;
                    }
                    
                
            }
        }
        ans = s.substr(start,end-start+1);
        return ans;
        
    }
};