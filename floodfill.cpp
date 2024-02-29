/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image
(with position (sr, sc) = (1, 1)), all
pixels connected by a path of the same color
as the starting pixel are colored with the new
color.Note the bottom corner is not colored 2,
because it is not 4-directionally connected to
the starting pixel.


Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.


Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)


code skeletom

class Solution{
    private:

    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int src, int sc, int newColor){

    }
};
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
    static void solve(int row, int col, vvi &image, vvi &ans,
                      int newColor, int currentColor, int delrow[], int delcol[])
    {
        ans[row][col] = newColor;

        int n, m;
        n = image.size();
        m = image[0].size();

        // traversing 4 neighbours

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == currentColor && ans[nrow][ncol] != newColor)
            {
                solve(nrow, ncol, image, ans, newColor, currentColor, delrow, delcol);
            }
        }
    }

public:
    static vvi floodfill(int sr, int sc, vvi &image, int newColor)
    {
        vvi ans = image;

        // getting the delrow, delcol
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int currentColor = image[sr][sc];

        solve(sr, sc, image, ans, newColor, currentColor, delrow, delcol);
        return ans;
    }
};

int main()
{
    vvi (*pfloodfill)(int, int, vvi &, int);
    pfloodfill = Solution::floodfill;

    vvi image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vvi ans = (*pfloodfill)(1, 1, image, 2);

    for (auto it : ans)
    {
        for (auto neighbour : it)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }
}