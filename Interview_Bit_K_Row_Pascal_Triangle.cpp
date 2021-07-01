//Question : https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int A) {
    A = A+1;
    int matrixA[A][A];
    for(int i = 0; i < A; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == (i) ){
                matrixA[i][j] = 1;
            } else {
                matrixA[i][j] = matrixA[i-1][j] + matrixA[i-1][j-1];
            }
        }
    }
    vector<int> pascalRow;
    for(int j = 0 ; j < A; j++) {
        pascalRow.push_back(matrixA[A-1][j]);
    }
    return pascalRow;
}
