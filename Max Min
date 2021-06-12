//Problem : Max Min(Interview Bit) https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
//Solution :  
//First approach was to go through the loop linearly while comparing each element for maximum and minimum.
//Second aproach used here is divide and conquer because it takes less number of comparisons.


//First Approach
int Solution::solve(vector<int> &A) {
    int maxElement = INT_MIN, minElement = INT_MAX;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > maxElement) {
            maxElement = A[i];
        }
        if(A[i] <= minElement) {
            minElement = A[i];
        }
    }
    return maxElement + minElement;
}


//Second Approach
struct partStatus{
    int maxElement;
    int minElement;
};

partStatus findSumMaxAndMin(vector<int> &A, int right, int left) {
    struct partStatus sol, rSol, lSol;
    if(right == left) {
        sol.maxElement = A[right];
        sol.minElement = A[left];
        return sol;
    }
    if(right == left +1){
        if(A[right] >= A[left]){
            sol.maxElement = A[right];
            sol.minElement = A[left];
        } else {
            sol.maxElement = A[left];
            sol.minElement = A[right];
        }
        return sol;
    }
    if(right < left) {
        int mid = (right + left)/2;
        rSol = findSumMaxAndMin(A, right, mid);
        lSol = findSumMaxAndMin(A, mid+1, left);
        if(rSol.maxElement > lSol.maxElement) {
            sol.maxElement = rSol.maxElement;
        } else {
            sol.maxElement = lSol.maxElement;
        }
        
        if(rSol.minElement < lSol.minElement) {
            sol.minElement = rSol.minElement;
        } else {
            sol.minElement = lSol.minElement;
        }
        return sol;
    }
    return sol;
}

int Solution::solve(vector<int> &A) {
    struct partStatus sol = findSumMaxAndMin(A,0, A.size()-1);
    return sol.maxElement + sol.minElement;
}
