class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int leftmax = height[0];
        int rightmax = height[n-1];
        int left = 0, right = n-1;
        while(left<=right)
        {
            if(leftmax<=rightmax)
            {
                leftmax = max(leftmax,height[left]);
                water += leftmax - height[left];
                left++;
            }
            else
            {
                rightmax = max(rightmax,height[right]);
                water += rightmax - height[right];
                right--;
            }
        }


        return water;
    }
};
