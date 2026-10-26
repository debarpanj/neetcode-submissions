class Solution {
public:
    int fun(int i,bool taken, vector<int>& prices,vector<vector<int>>& DP)
    {
        int n = prices.size();
        if(i==n)return 0;
        if(DP[i][taken]!=-1)return DP[i][taken];
        int val = fun(i+1,taken,prices,DP);
        if(!taken)
        {
            val = max(val,fun(i+1,true,prices,DP)-prices[i]);
        }
        else
        {
            val = max(val,fun(i+1,false,prices,DP)+prices[i]);
        }
        return DP[i][taken] = val;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>DP(prices.size(),vector<int>(2,-1));
        return fun(0,false,prices,DP);
    }
};