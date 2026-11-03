class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n = nums.size();
        k++;

        for(int i=0;i<min(k,n);i++)
        {
            if(s.find(nums[i])!=s.end())return true;
            s.insert(nums[i]);
        }

        for(int i=k;i<n;i++)
        {
           s.erase(nums[i-k]);
           if(s.find(nums[i])!=s.end()) return true;
           s.insert(nums[i]);
        }

        return false;
    }
};