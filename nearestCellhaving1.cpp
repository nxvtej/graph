/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.


Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.


Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.




Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
*/

/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
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
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vvi visited(n, vi(m, 0));
        vvi distance(n, vi(m, 0));

        // forgot ot initilize queue
        queue<pair<pair<int, int>, int>> q;

        // traverse all 1's present
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==1)
                {
                    // mark viisted, distance 0, push in queue;
                    visited[i][j] = 1;
                    // distance[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

                // setting delta
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // after this start with bhs
        int steps = 0;
        while (!q.empty())
        {
            // get data
            int row = q.front().first.first;
            int col = q.front().first.second;
            steps = q.front().second;

            cout << "printing values for steps " << steps << " ";
            q.pop();

            // forgot to add the  steps into distance vector<int>
            distance[row][col] = steps;
            // after all these go to their 4 neighbour's
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // now check if thya re valid
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol])
                {
                    q.push({{nrow, ncol}, steps + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return distance;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    cout << "given grid\n";
    for (auto it : grid)
    {
        for (auto neighbour : it)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }
    int V = 4, E = 2;
    vector<vector<int>> ans = solution.nearest(grid);
    cout << "updated distance\n";
    for (auto it : ans)
    {
        for (auto neighbour : it)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }
    return 0;
}

*/

/*
fucking gemini
i didnt though of assiging max to these
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define qi queue<int>
#define qp queue<pair<int, int>>

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vvi distance(n, vi(m, INT_MAX)); // Initialize distance matrix to maximum value

        // Create a queue to perform Breadth-First Search (BFS)
        queue<pair<int, int>> q;

        // Start BFS from all cells containing 1
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    distance[i][j] = 0; // Update distance to 0 for starting 1s
                    q.push({i, j});
                }
            }
        }

        // Setting delta values for row and column movements
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Perform BFS
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all four neighbors
            for (int i = 0; i < 4; ++i)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check if the neighbor is valid (within bounds and unvisited)
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && distance[nrow][ncol] == INT_MAX)
                {
                    distance[nrow][ncol] = distance[row][col] + 1; // Update distance
                    q.push({nrow, ncol});                          // Add neighbor to queue
                }
            }
        }

        return distance;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    cout << "given grid\n";
    for (auto it : grid)
    {
        for (auto neighbour : it)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> ans = solution.nearest(grid);
    cout << "updated distance\n";
    for (auto it : ans)
    {
        for (auto neighbour : it)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    return 0;
}
