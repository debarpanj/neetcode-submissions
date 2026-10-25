class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int F[2001] = {0};
        for(int i=0;i<nums.size();i++)F[nums[i]+1000]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<=2000;i++)
        {
            if(F[i]!=0)
            {
                pq.push({F[i],i-1000});
                if(pq.size()>k)pq.pop();
            }
        }
        
        vector<int>ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
