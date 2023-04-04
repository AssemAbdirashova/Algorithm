#include <iostream>

using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;

    int towns[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> towns[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (towns[i][j] == 1 && towns[j][i] == 1 )
            {
                cnt++;
            }
        }
    }
    cout << cnt/2;
}

