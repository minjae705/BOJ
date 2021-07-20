#include <iostream>
using namespace std;

char map[3333][6666];
void star(int size, int i, int j) {
    if(size == 3){
        map[i][j] = '*';
        map[i+1][j-1] = '*';
        map[i+1][j+1] = '*';
        for(int y=j-2; y<=j+2; y++)
            map[i+2][y] = '*';
        return;
    }
    star(size/2, i, j);
    star(size/2, i+size/2, j-size/2);
    star(size/2, i+size/2, j+size/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<2*n; j++)
            map[i][j] = ' ';
    star(n, 0, n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n; j++)
            cout << map[i][j];
        cout << '\n';
    }
    return 0;
}
