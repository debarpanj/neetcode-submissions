class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;

        for(int k=0;k<n-2;k++)
        {
            if(k>0 && nums[k] == nums[k-1])continue;
            int i = k+1,j=n-1;
            while(i<j)
            {
                if(nums[i] + nums[j] == -nums[k])
                {
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i+1<j && nums[i+1]==nums[i])i++;
                    while(j-1>i && nums[j-1] ==nums[j])j--;
                    i++;
                    j--;
                    
                }
                else if(nums[i] + nums[j] < -nums[k]){
                   i++;
                }
                else j--;
            }
        }

        return res;
    }
};
