class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int leftmax = -1;
        int rightmax = -1;
        int left = 0, right = n-1;
        while(left<=right)
        {
            if(leftmax<=rightmax)
            {
                water += max(0,leftmax - height[left]);
                leftmax = max(leftmax,height[left]);
                left++;
            }
            else
            {
                water += max(0,rightmax - height[right]);
                rightmax = max(rightmax,height[right]);
                right--;
            }
        }


        return water;
    }
};
