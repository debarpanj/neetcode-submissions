class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(s.find(board[i][j])==s.end()) s.insert(board[i][j]);
                    else return false;
                }
            }
            s.clear();
        }

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    if(s.find(board[j][i])==s.end()) s.insert(board[j][i]);
                    else return false;
                }
            }
            s.clear();
        }


        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            if(s.find(board[k][l])==s.end()) s.insert(board[k][l]);
                            else return false;
                        }
                    }
                }
                s.clear();
            }
        }

        return true;
    }
};
