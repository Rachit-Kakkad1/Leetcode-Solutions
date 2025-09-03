#include <stdio.h>

void spiralOrder(int m, int n, int matrix[m][n]) {
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
       
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;


        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

      
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top (if column remains)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("Example 1:\n");
    spiralOrder(3, 3, matrix1); 
    printf("\n\n");

    printf("Example 2:\n");
    spiralOrder(3, 4, matrix2); 
    printf("\n");

    return 0;
}
