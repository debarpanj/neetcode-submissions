class Solution {
public:
    bool is_pal(const string &s, int l, int r, bool forgive)
    {
        int i = l, j = r;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                if(!forgive)return false;
                return is_pal(s,i,j-1,false) || is_pal(s,i+1,j,false);
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        return is_pal(s,0,s.length()-1,true);
    }
};