class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1 && nums[0]==val)return 0;
        int j =n-1,i=0;
        int count=0;
        while(i<=j)
        {
            if(nums[i]==val)
            {
                count++;
                swap(nums[i],nums[j]);
                j--;
            }
            else i++;
        }

        return i;
        
    }
};