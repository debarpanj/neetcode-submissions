class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;

        for (int k = 0;k<n-3;k++)
        {
            if(k>0 && nums[k] == nums[k-1])continue;
            for(int l =k+1;l<n-2;l++)
            {
                if(l>k+1 && nums[l-1] == nums[l])continue;
                int i = l+1,j=n-1;
                long long key = 1LL*target - nums[k] - nums[l];
                while(i<j)
                {
                    if(1LL*nums[i]+ nums[j] == key)
                    {
                        res.push_back({nums[k],nums[l],nums[i],nums[j]});
                        while(i+1 <j && nums[i+1]==nums[i])i++;
                        while(j-1>i && nums[j-1]==nums[j])j--;
                        i++;
                        j--;
                    }
                    else if(1LL*nums[i]+ nums[j] < key) i++;
                    else j--;
                }
            }
        }

        return res;

    }
};