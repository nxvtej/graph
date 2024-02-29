/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.


Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).


Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

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
private:
    static int max(int a, int b)
    {
        return a > b ? a : b;
    }

public:
    static int rottenOranges(vvi &grid)
    {
        // first step to get size of the matrix
        int n, m;
        n = grid.size();
        m = grid[0].size();

        //  intilize queue<pari<pair

        qpf q;

        int visited[n][m];
        int cntFresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }

                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }

        // setting poiinter to the max fubction
        int (*pmax)(int, int);
        pmax = &max;

        int timer = 0, cnt = 0;
        // now we have rotten oranges into the queue ready to ben takeen out \

        while (!q.empty())
        {
            // extract dat from queue

            int r, c, t;
            r = q.fff;
            c = q.ffs;
            t = q.fs;

            q.pop();

            timer = pmax(t, timer);

            // ḥave delta values in array for 4 neighbour aproach
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                // check if they are valid

                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if (cntFresh == cnt)
        {
            return timer;
        }
        return -1;
    }
};

int main()
{
    vvi grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    int (*prottenOranges)(vvi &);
    prottenOranges = Solution::rottenOranges;
    cout << (*prottenOranges)(grid) << " ";
}

/*

SC - O(n*m)*O(n*m)*O(n*m) = ~O(n*m)
grid, visited, queue
can optimizer it by removing grid/visited but won't be able to do this in interview as it would alter input data

TC - O(n*m)+O(n*m)+O(n*m*4) = ~ O(n*m)
creating visited, rottenoranges(worst case entire matrix is 1 and one 2)

*/