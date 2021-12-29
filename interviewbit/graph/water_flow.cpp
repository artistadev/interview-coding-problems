/*
Problem Description
    Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.
    Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
    Find the number of cells from where water can flow to both the Blue and Red lake.
Problem Constraints
    1 <= M, N <= 1000
    1 <= A[i][j] <= 109
Input Format
    First and only argument is a 2D matrix A.
Output Format
    Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.
Example Input
Input 1:
 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]
Input 2:
 A = [
       [2, 2]
       [2, 2]
     ]
Example Output
Output 1:
    7
Output 2:
    4
Example Explanation
Explanation 1:
 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.
Explanation 2:
    Water can flow from all cells.
*/

vector<pair<int, int>> dir{{1, 0}, {-1, 0}, { 0, -1}, { 0, 1}};

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, int &row, int &col, vector<vector<int>> &matrix) {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i <4; i++) {
            int newX = x + dir[i].first;
            int newY = y + dir[i].second;

            if(newX < 0 || newY < 0 || newX >= row || newY >= col || visited[newX][newY] == true)
                continue;
            if(matrix[x][y] <= matrix[newX][newY]) {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();

    vector<vector<bool>> redVisited(row, vector<bool>(col, false));
    vector<vector<bool>> blueVisited(row, vector<bool>(col, false));
    queue<pair<int, int>> qBlue, qRed;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 || j == 0){
                qBlue.push({ i, j });
                blueVisited[i][j] = true;
            }
            if(i == row-1 || j == col-1) {
                qRed.push({ i, j });
                redVisited[i][j] = true;
            }
        }
    }

    bfs(qBlue, blueVisited, row, col, A);
    bfs(qRed, redVisited, row, col, A);

    int ans = 0;
    for(int i = 0; i< row; i++) {
        for(int j = 0; j< col; j++) {
            if(redVisited[i][j] && blueVisited[i][j])
                ans++;
        }
    }
    return ans;
}
