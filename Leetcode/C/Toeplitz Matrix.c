bool isToeplitzMatrix(int **matrix, int matrixRowSize, int *matrixColSizes) {
    int flag = 1;
    for(int r=1; r<matrixRowSize; r++){
        for(int i=1; i < *matrixColSizes  && i<=r; i++)
            if(matrix[r][i] != matrix[r-i][0]){
                flag = 0;
                break;
            }

        for(int j=r+1; j<*matrixColSizes; j++)
             if(matrix[r][j] != matrix[0][j - r]){
                flag = 0;
                break;
            }
        if(flag == 0)
            break;
    }
    
    return flag ==1? true: false;
}