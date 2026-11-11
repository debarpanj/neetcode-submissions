class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int sum = 0,i=0,j=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>=target && i<=j)
            {
                ans = min(ans,j-i+1);
                sum-=nums[i];
                i++;
                
            }
            j++;
        }

        return ans==INT_MAX ?0:ans;
    }
};