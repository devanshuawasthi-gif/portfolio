#define MOD 1000000007

int* pathsWithMaxScore(char** board, int boardSize, int* returnSize) {
    int n = boardSize;

    int score[n][n];
    int ways[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            score[i][j] = -1;
            ways[i][j] = 0;
        }
    }

    score[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {

            if (board[i][j] == 'X')
                continue;

            if (i == n - 1 && j == n - 1)
                continue;

            int best = -1;
            long long cnt = 0;

            int dx[3] = {1, 0, 1};
            int dy[3] = {0, 1, 1};

            for (int k = 0; k < 3; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= n || nj >= n)
                    continue;

                if (score[ni][nj] == -1)
                    continue;

                if (score[ni][nj] > best) {
                    best = score[ni][nj];
                    cnt = ways[ni][nj];
                } else if (score[ni][nj] == best) {
                    cnt = (cnt + ways[ni][nj]) % MOD;
                }
            }

            if (best == -1)
                continue;

            int val = 0;
            if (board[i][j] != 'E' && board[i][j] != 'S')
                val = board[i][j] - '0';

            score[i][j] = best + val;
            ways[i][j] = (int)cnt;
        }
    }

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    if (ways[0][0] == 0) {
        ans[0] = 0;
        ans[1] = 0;
    } else {
        ans[0] = score[0][0];
        ans[1] = ways[0][0];
    }

    return ans;
}