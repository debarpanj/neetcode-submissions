class Solution {
public:
    int maxArea(vector<int>& heights) {
        int  n = heights.size();
        int i=0, j=n-1;
        int maxarea = 0;
        while(i<j)
        {
           maxarea = max(maxarea,(j-i) * min(heights[i],heights[j]));
           if(heights[i]<=heights[j])i++;
           else j--;
        }
        return maxarea;
    }
};
