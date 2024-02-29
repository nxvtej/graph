/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0
There are two islands :- one is colored in blue
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)


given skeleton


*/
#include <iostream>
#include <vector>
#include <queue>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

#define pb push_back

#define qi queue<int>
#define qp queue<pair<int, int>>
#define ff front().first
#define fs front().second

using namespace std;

class Solution
{
private:
    static void bfs(int row, int col, vvi &visited, vvc &grid, int n, int m)
    {
        visited[row][col] = 1;

        // cout << "printing from bfs" << row << col << "\n";
        qp q;
        q.push({row, col});

        while (!q.empty())
        {
            int row, col;
            row = q.ff;
            col = q.fs;

            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                    {

                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    static int numberofIsland(vvc &grid)
    {
        int n, m;
        n = grid.size();
        m = grid[0].size();

        // cout<<n<<" "<<m<<" ";
        vvi visited(n, vi(m, 0));
        int count = 0;

        void (*pbfs)(int, int, vvi &, vvc &, int, int);
        pbfs = Solution::bfs;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (visited[row][col] == 0 && grid[row][col] == '1')
                {
                    count++;
                    // cout << "calling bfs through pbfs"
                    // << " ";
                    (*pbfs)(row, col, visited, grid, n, m);
                }
            }
        }
        // cout << "printing from numberofisland funcvtion" << count << "\n";

        return count;
    }
};

int main()
{
    int (*pnumberofisland)(vvc &);
    pnumberofisland = Solution::numberofIsland;

    vvc grid = {{'0', '1'}, {'1', '0'}, {'1', '1'}, {'1', '0'}};
    cout << (*pnumberofisland)(grid);
}