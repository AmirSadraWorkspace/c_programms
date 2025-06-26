#include <stdio.h>

/*char puzzle[9][9] = {
	{5, 3, 0, 0, 7, 0, 0, 0, 0},
	{6, 0, 0, 1, 9, 5, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8, 0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	{0, 6, 0, 0, 0, 0, 2, 8, 0},
	{0, 0, 0, 4, 1, 9, 0, 0, 5},
	{0, 0, 0, 0, 8, 0, 0, 7, 9},

};


#include <stdio.h>

int puzzle[9][9];

int find_free(int *x, int *y) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return 1;
            }
    return 0;
}

int is_valid(int n, int x, int y) {
    for (int i = 0; i < 9; i++)
        if (puzzle[x][i] == n || puzzle[i][y] == n)
            return 0;

    int x_square = (x / 3) * 3;
    int y_square = (y / 3) * 3;

    for (int i = x_square; i < x_square + 3; i++)
        for (int j = y_square; j < y_square + 3; j++)
            if (puzzle[i][j] == n)
                return 0;

    return 1;
}

int solve() {
    int x, y;
    if (find_free(&x, &y) == 0)
        return 1;

    for (int i = 1; i <= 9; i++) {
        if (is_valid(i, x, y)) {
            puzzle[x][y] = i;
            if (solve())
                return 1;
            puzzle[x][y] = 0;
        }
    }
    return 0;
}

void draw() {
    for (int temp = 0; temp < 22; temp++)
        printf("-");
    printf("\n");

    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6)
                printf("|");
            printf("%d ", puzzle[i][j]);
        }
        if (i == 2 || i == 5)
            printf("\n------------------------\n");
        else
            printf("|\n");
    }

    for (int temp = 0; temp < 22; temp++)
        printf("-");
    printf("\n");
}

int main() {
    printf("Enter the Sudoku puzzle (9x9), use 0 for empty cells:\n");

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            printf("Cell [%d][%d]: ", i, j);
            scanf("%d", &puzzle[i][j]);
        }

    printf("\nThe entered Sudoku puzzle is:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }

    if (solve())
        draw();
    else
        printf("i can not solve it wow...\n");

    return 0;
}


*/



#include <stdio.h>

int puzzle[9][9];  // ????? global

int solve();
void draw();
int find_free(int *x, int *y);
int is_valid(int n, int x, int y);

int main() {
    printf("Enter the Sudoku puzzle (9x9), use 0 for empty cells:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("Cell [%d][%d]: ", i, j);
            scanf("%d", &puzzle[i][j]);
        }
    }

    printf("\nThe entered Sudoku puzzle is:\n");
    draw();

    if (solve()) {
        printf("\nSolved Sudoku puzzle:\n");
        draw();
    } else {
        printf("I cannot solve it, wow...\n");
    }

    return 0;
}

void draw() {
    for (int temp = 0; temp < 22; temp++)
        printf("-");
    printf("\n");

    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6)
                printf("| ");
            printf("%d ", puzzle[i][j]);
        }
        printf("|\n");
        if (i == 2 || i == 5)
            printf("----------------------\n");
    }

    for (int temp = 0; temp < 22; temp++)
        printf("-");
    printf("\n");
}

int find_free(int *x, int *y) {
    for (int i = 0; i < 9 ; i++) {
        for (int j = 0; j < 9 ; j++) {
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int n, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[x][i] == n || puzzle[i][y] == n)
            return 0;
    }

    int x_square = (x / 3) * 3;
    int y_square = (y / 3) * 3;

    for (int i = x_square; i < x_square + 3; i++)
        for (int j = y_square; j < y_square + 3; j++)
            if (puzzle[i][j] == n)
                return 0;

    return 1;
}

int solve() {
    int x, y;
    if (!find_free(&x, &y))
        return 1;

    for (int i = 1; i <= 9; i++) {
        if (is_valid(i, x, y)) {
            puzzle[x][y] = i;
            if (solve())
                return 1;
            puzzle[x][y] = 0;
        }
    }
    return 0;
}
