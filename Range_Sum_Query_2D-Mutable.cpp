class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        row_size = matrix.size();
        col_size = matrix[0].size();
        bin_indexed_arr.resize(row_size+1, vector<int>(col_size+1, 0));
        mat.resize(row_size, vector<int>(col_size,0));
        for( int i = 0; i < row_size; i++ )
        {
            for( int j = 0; j < col_size; j++ )
            {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        for( int i=row+1; i<=row_size; i+=(i&-i) ) 
        {
            for( int j=col+1; j<=col_size; j+=(j&-j) ) 
            {
                bin_indexed_arr[i][j] += diff;
            }
        }
        mat[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum += (get_sum(row2+1, col2+1) - get_sum(row1,col2+1) - get_sum(row2+1,col1) + get_sum(row1, col1));
        return sum;
    }
    
    int get_sum(int row, int col)
    {
        int sum = 0;
        for( int i=row; i>0; i-=(i&-i) ) 
        {
            for( int j=col; j>0; j-=(j&-j) ) 
            {
                sum += bin_indexed_arr[i][j];
            }
        }
        return sum;
    }
    int row_size;
    int col_size;
    vector<vector<int>> mat;
    vector<vector<int>> bin_indexed_arr;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
