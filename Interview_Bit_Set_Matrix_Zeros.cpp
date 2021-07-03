//Question: https://www.interviewbit.com/problems/set-matrix-zeros/
void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<int> rows;
    set<int> columns;
    int rowSize = A[0].size();

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < rowSize; j++) {
            if(A[i][j] == 0) {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }

    for(int i = 0; i < A.size(); i++) {
        for(int j =0; j < rowSize; j++) {
            if(rows.count(i) != 0 || columns.count(j) != 0){
                A[i][j] = 0;
            }
        }
    }
}
