/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

Expected Time Complexity: O(n * m)

Expected Space Complexity: O(n * m)

Constraints:

1 <= n, m <= 500
grid[i][j] == 0 or 1

*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution
{
public:
    static int numberofEnclaves(vvi &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vvi visited(n, vi(m, 0));
        qp q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // either first/last row or col
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            // get neighbours
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        // now final get the count
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!visited[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    int n = 5, m = 4;
    vvi grid = {{0, 0, 0, 0},
                {1, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}};

    int (*pregionProblem)(vvi &);
    pregionProblem = Solution::numberofEnclaves;
    int output = (*pregionProblem)(grid);
    // for (auto it : output)
    // {
    //     for (auto neighbour : it)
    //     {
    //         cout << "'" << neighbour << "' ";
    //     }
    //     cout << "\n";
    // }
    cout << output << " ";
    return 0;
}
