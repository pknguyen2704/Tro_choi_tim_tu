#include <iostream>
#include <string>
using namespace std;

const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int MAX_M = 105;
const int MAX_N = 105;

int m, n;
char arr[MAX_M*3+5][MAX_N*3+5];
string tmp;
bool flag = false;
int start_x, start_y, finish_x, finish_y;

bool inside(int x, int y)
{
    return x >= m+1 && x <= 2*m && y >= 1+n && y <= 2*n;
}

void InitData()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for(int i = m+1; i <= 3*m; i++)
        for(int j = 1; j <=n; j++)
            arr[i][j] = arr[i-m][j];
    for(int i = 1; i <= 3*m; i++)
        for(int j = n + 1; j <= 3*n; j++)
            arr[i][j] = arr[i][j-n];
    // for(int i = 1; i <= 3*m; i++)
    // {
    //     for(int j = 1; j <= 3*n; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
}
int main()
{
    InitData();
    int q;
    cin >> q;
    while(q--)
    {
        string str;
        cin >> str;

        bool checkInputError = false;
        for(int i = 0; i < int(str.length()); i++)
        {
            if(str[i] >= '0' && str[i] <= '9'){
                checkInputError = true;
                break;
            }
        }
        if(checkInputError == true)
            cout << "input error" << endl;
        else
        {
            flag = false;
            for(int i = m+1; i <= 2*m; i++)
            {
                for(int j = n+1; j <= 2*n; j++)
                {
                    tmp = "";
                    if(arr[i][j] == str[0])
                    {
                        start_x = i;
                        start_y = j;
                        tmp += str[0];
                        for(int k = 0; k < 8; k++)
                        {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(arr[x][y] == str[1])
                            {
                                int h = 1;
                                while(arr[x][y] == str[h])
                                {
                                    tmp+=arr[x][y];
                                    if(tmp == str)
                                    {
                                        flag = true;
                                        cout << start_x-m << " " << start_y-n << " ";
                                        if(x > 2*m)
                                            x-=2*m;
                                        if(y > 2*n)
                                            y-=2*n;
                                        if(x >= m)
                                            x-=m;
                                        if(y >= n)
                                            y-=n;
                                        cout << x << " " << y << endl;
                                        //cout << tmp << endl;
                                        break;
                                    }
                                    x+=dx[k];
                                    y+=dy[k];
                                    h++;
                                }
                            }
                        }
                    }
                }
            }
            if(flag == false)
                cout << "not found" << endl;
        }
        
    }
    return 0;
}
