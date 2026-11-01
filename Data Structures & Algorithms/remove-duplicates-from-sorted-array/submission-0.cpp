class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int k =0;

        while(i<n)
        {
            nums[k++] = nums[i];
            int j = i+1;
            while(j<n && nums[j]==nums[i])
            {
                j++;
            }
            i=j;
        }
        return k;
    }
};