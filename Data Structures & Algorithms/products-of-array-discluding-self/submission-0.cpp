class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
       vector<int>res(n);
       res[n-1] = nums[n-1];

       for(int i=n-2;i>=0;i--)
       {
          res[i] = nums[i] * res[i+1];
       }

       int prefix= 1;

       for(int i=0;i<n-1;i++)
       {
        res[i] = prefix * res[i+1];
        prefix*=nums[i];
       }
       res[n-1] = prefix;
       return res;    
    }
};
