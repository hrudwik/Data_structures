#include <bits/stdc++.h>

using namespace std;

int regionLength(vector<vector<int>> matrix, vector<vector<int>> visited, int n, int i, int j)
{
    int len = 0;
    if(i>=0 && i<=n-1 && j>=0 && j<=n-1)
    {
        cout<<"a."<<i<<" "<<j<<" "<<matrix[i][j]<<" "<<visited[i][j]<<" "<<len<<endl;
        if(matrix[i][j] == 1 && visited[i][j] == 0)
        {
            visited[i][j] = 2;
            len +=1;
            cout<<"b."<<i<<" "<<j<<" "<<matrix[i][j]<<" "<<visited[i][j]<<" "<<len<<endl;
            len += regionLength(matrix, visited, n, i-1, j-1);
            len += regionLength(matrix, visited, n, i-1, j);
            len += regionLength(matrix, visited, n, i-1, j+1);
            len += regionLength(matrix, visited, n, i, j-1);
            len += regionLength(matrix, visited, n, i, j+1);
            len += regionLength(matrix, visited, n, i+1, j-1);
            len += regionLength(matrix, visited, n, i+1, j);
            len += regionLength(matrix, visited, n, i+1, j+1);
        }
    }
    return len;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) 
{
    int n = matrix[0].size(), max_len = 0, len = 0;
    vector<vector<int>> visited(n);
    
    for (int i = 0; i < n; i++) 
    {
        visited[i] = vector<int>(n); 
        for (int j = 0; j < n; j++) 
        {
            visited[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if(matrix[i][j]==1 && visited[i][j] == 0)
            {
                if(i==0 && j==0)
                {
                    cout<<"1)"<<i<<" "<<j<<" "<<matrix[i][j]<<" "<<visited[i][j]<<" "<<len<<endl;
                    len = regionLength(matrix, visited, n, i, j);
                    cout<<"2)"<<i<<" "<<j<<" "<<matrix[i][j]<<" "<<visited[i][j]<<" "<<len<<endl;
                }
                if(len>max_len)
                {max_len = len;}
                len =0;
            }
        }
    }
    return max_len;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
