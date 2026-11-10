class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        auto is_ok = [&]()
        {
           int max_freq = 1;
           int count=0;
           for(int i=0;i<26;i++)
           {
              if(mp[i]>0)
              {
                count+=mp[i];
                max_freq = max(max_freq,mp[i]);
              }
           }
           return (count - max_freq)<=k;
        };

        int i=0,j=0,n=s.length();
        int max_len = 1;

        while(j<n)
        {
           mp[s[j]-'A']++;
           while(!is_ok() && i<j)
           {
             mp[s[i++]-'A']--;
           }

           max_len = max(max_len,j-i+1);
           j++;

        }

        return max_len;
    }
};
