class Solution {
public:
bool check(int i , int j,string& s, vector<vector<int>>&dp)
{
    if(i>=j) return true ; // when they move and i beat j means we got our palindrome ..
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==s[j])
    {
        return dp[i][j]=check(i+1,j-1,s,dp);
    }
   else return dp[i][j]=false ;
}
    string longestPalindrome(string s)
     {
        int maximum_length=INT_MIN;
        int start_index=-1;
        vector<vector<int>>dp(s.size()+1, vector<int>(s.size()+1 ,-1));
        for(int i=0 ; i<s.size() ;i++)
        {
            for(int j=i ; j<s.size() ;j++)
            {
               
                if( check(i,j,s,dp) && (j-i+1)>maximum_length)
                {
                    maximum_length=(j-i+1);
                    start_index=i;
                }
            }
        }

        return s.substr(start_index,maximum_length);
    }
};