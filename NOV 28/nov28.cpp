class Solution {
public:
    int p;
    int q;
    void ps(vector<vector<int>>& m, int i, int j){

        if(i == 0 && j < 0)return;
        if(j < 0 ){
            ps(m, i -1, q -1);
            return;
        }
        
        if(i == p -1 && j == q -1){
            ps(m, i , j -1);

        }else if(i == p -1){
            m[i][j] = m[i][j] + m[i][j +1];
            ps(m, i , j -1);

        }else if(j == q -1){
            m[i][j] = m[i][j] + m[i +1][j];
            ps(m, i , j -1);

        }else{
            m[i][j] = m[i][j] + min(m[i +1][j], m[i][j +1]);
            ps(m, i, j - 1);

        }
        cout << i << j << '\n';
    }
//go through each element sideways and ake note of lower and right element 
    int minPathSum(vector<vector<int>>& grid) {
        this->p = grid.size();
        this->q = grid[0].size();
        ps(grid, p -1, q -1);
        return grid[0][0];
    }
};
