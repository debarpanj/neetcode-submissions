class Solution {
public:
    void merge_sort(int l,int r, vector<int>&nums)
    {
        if(l>=r) return;
        int m = (l+r) / 2;

        merge_sort(l,m,nums);
        merge_sort(m+1,r,nums);
        merge(l,m,r,nums);

    }

    void merge(int l,int m,int r, vector<int> &nums)
    {
        int n1 = m-l+1;
        int n2 = r-m;

        vector<int>L(nums.begin() +  l, nums.begin() + m + 1);
        vector<int>R(nums.begin() + m + 1, nums.begin() + r + 1);

        int k = l;
        int i = 0,j = 0;

        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                nums[k] = L[i];
                i++;
            }
            else 
            {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1)
        {
            nums[k++] = L[i++];
        }

        while(j<n2)
        {
            nums[k++] = R[j++];
        }
    
        
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0,nums.size()-1,nums);
        return nums;
    }
};