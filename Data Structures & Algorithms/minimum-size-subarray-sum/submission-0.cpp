class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        auto is_possible = [&](int mid)
        {
           int sum = 0;
           for(int i=0;i<mid;i++)
           {
              sum+=nums[i];
              if(sum>=target)return true;
           }
           for(int i=mid;i<n;i++)
           {
             sum-=nums[i-mid];
             sum+=nums[i];
             if(sum>=target)return true;
           }
           return false;
        };
        int ans = 0;
        int low = 1,high = n;
        while(low<=high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};