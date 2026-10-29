class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = -1,j=n;

        int k = 0;
        while(k<j)
        {
            if(nums[k]==0)
            {
                i++;
                swap(nums[i],nums[k]);
                k++;
            }
            else if(nums[k]==2)
            {
                j--;
                swap(nums[j],nums[k]);
            }
            else k++;
        }
    }
};