/*
 1901. 寻找峰值 II
 一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

 给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并 返回其位置 [i,j] 。

 你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

 要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法
 */

int* createResult(int row, int col) {
    int *result = malloc(sizeof(int)*2);
    result[0] = row;
    result[1] = col;
    return result;
}

// 暴力查找
int* findPeakGridHelper2(int** mat, int midRow, int midCol, int maxRowSize, int maxColSize) {
    int midValue = mat[midRow][midCol];
    int tValue = -1;
    int bValue = -1;
    int lValue = -1;
    int rValue = -1;
    
    if (midRow > 0) {
        tValue = mat[midRow-1][midCol];
    }
    if (midRow < maxRowSize-1) {
        bValue = mat[midRow+1][midCol];
    }
    if (midCol > 0) {
        lValue = mat[midRow][midCol-1];
    }
    if (midCol < maxColSize-1) {
        rValue = mat[midRow][midCol+1];
    }
    
    if (midValue > tValue && midValue > lValue && midValue > rValue && midValue > bValue) {
        return createResult(midRow, midCol);
    }
    
    if (lValue > rValue && lValue > tValue && lValue > bValue) {
        return findPeakGridHelper2(mat, midRow, midCol-1, maxRowSize, maxColSize);
    }
    if (rValue > tValue && rValue > bValue) {
        return findPeakGridHelper2(mat, midRow, midCol+1, maxRowSize, maxColSize);
    }
    
    if (tValue > midValue) {
        return findPeakGridHelper2(mat, midRow-1, midCol, maxRowSize, maxColSize);
    } else {
        return findPeakGridHelper2(mat, midRow+1, midCol, maxRowSize, maxColSize);
    }
}

// 二分查找
int* findPeakGridHelper(int** mat, int startRow, int startCol, int rowSize, int colSize, int maxRowSize, int maxColSize) {
    int midRow = (startRow+rowSize)/2;
    int midCol = (startCol+colSize)/2;
    
    int midValue = mat[midRow][midCol];
    int tValue = -1;
    int bValue = -1;
    int lValue = -1;
    int rValue = -1;
    
    if (midRow > 0) {
        tValue = mat[midRow-1][midCol];
    }
    if (midRow < maxRowSize-1) {
        bValue = mat[midRow+1][midCol];
    }
    if (midCol > 0) {
        lValue = mat[midRow][midCol-1];
    }
    if (midCol < maxColSize-1) {
        rValue = mat[midRow][midCol+1];
    }
    
    if (midValue > tValue && midValue > lValue && midValue > rValue && midValue > bValue) {
        return createResult(midRow, midCol);
    }
    if (rValue > midValue) {
        return findPeakGridHelper(mat, startRow, midCol+1, rowSize, colSize, maxRowSize, maxColSize);
    }
    if (lValue > midValue) {
        return findPeakGridHelper(mat, startRow, startCol, rowSize, midCol, maxRowSize, maxColSize);
    }
    if (tValue > midValue) {
        return findPeakGridHelper2(mat, midRow-1, midCol, maxRowSize, maxColSize);
    } else {
        return findPeakGridHelper2(mat, midRow+1, midCol, maxRowSize, maxColSize);
    }
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    *returnSize = 2;
    return findPeakGridHelper(mat, 0, 0, matSize, matColSize[0], matSize, matColSize[0]);
}

// ------ 官方题解
// 思路是二分行数，然后遍历行找出改行中最大值的位置
int maxElement(int *row, int n) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (row[i] < row[j]) {
            i = j;
        }
    }
    return i;
}

int* findPeakGrid(int **mat, int matSize, int *matColSize, int *returnSize) {
    int m = matSize, n = matColSize[0];
    int low = 0, high = m - 1;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = maxElement(mat[i], n);
        if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j]) {
            high = i - 1;
            continue;
        }
        if (i + 1 < m && mat[i][j] < mat[i + 1][j]) {
            low = i + 1;
            continue;
        }
        int *ret = (int *)malloc(sizeof(int) * 2);
        ret[0] = i;
        ret[1] = j;
        *returnSize = 2;
        return ret;
    }
    *returnSize = 0;
    return NULL; // impossible
}
