#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n + 1, 0), right(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            else
            {
                right[i] = n;
            }
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            else
            {
                left[i] = -1;
            }
            st.push(i);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, heights[i] * (right[i] - left[i] - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>> &mat)
    {

        int rows = mat.size();
        int cols = mat[0].size();
        int maxi = 0;
        vector<vector<int>> matrix;
        for (int i = 0; i < rows; i++)
        {
            vector<int> temp;
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == '1')
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(0);
                }
            }
            matrix.push_back(temp);
        }

        for (int i = 0; i < rows; i++)
        {
            if (i > 0)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (matrix[i][j] != 0)
                    {
                        matrix[i][j] += matrix[i - 1][j];
                    }
                }
            }

            maxi = max(maxi, largestRectangleArea(matrix[i]));
        }
        return maxi;
    }
};