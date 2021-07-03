//Question : https://www.interviewbit.com/problems/spiral-order-matrix-ii/
vector<vector<int> > Solution::generateMatrix(int A) {
    int matrix[A][A];
    int count = 1;
    int num = A * A;
    int startI = 0;
    int startJ = 0;
    int sizeOfMatrix = A;
    int startIPtr, startJPtr;

    while(count <= num) {
        if(sizeOfMatrix == 1) {
            matrix[startI][startJ] = count;
            count++;
            continue;
        } else {
            startIPtr = startI;
            startJPtr = startJ;
            for(int z = 0; z < 4; z++) {
                for(int i = 0; i < sizeOfMatrix; i++) {
                    if(z == 0) {
                        matrix[startIPtr][startJPtr+i] = count;
                        count += 1;
                    }
                    else if(z == 1 && i != (sizeOfMatrix-1)) {
                        matrix[startIPtr+i+1][startJPtr+sizeOfMatrix-1] = count;
                        count += 1;
                    }
                    else if(z == 2 && i != (sizeOfMatrix-1)) {
                        matrix[startIPtr+sizeOfMatrix - 1][startJPtr+sizeOfMatrix-1 -i-1] = count;
                        count += 1;
                    }
                    else if(z == 3 && i < (sizeOfMatrix-2)) {
                        matrix[startIPtr+sizeOfMatrix-1-i-1][startJPtr] = count;
                        count += 1;
                    }
                }
            }
            startI += 1;
            startJ += 1;
            sizeOfMatrix -= 2;
        }
    }
    vector<vector<int>> sol;
    for(int i = 0; i < A; i++) {
        vector<int> row;
        for(int j = 0; j < A; j++ ) {
            row.push_back(matrix[i][j]);
        }
        sol.push_back(row);
    }
    return sol;
}
