class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int left = height[0];
        vector<int>right(n);
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1],height[i]);
        }
        int t;
        for(int i=1;i<n-1;i++)
        {
            t = min(left,right[i+1]);
            water+=(t>height[i])?t-height[i]:0;
            left = max(left,height[i]);
        }

        return water;
    }
};
