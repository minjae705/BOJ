#include <iostream>
#include <string>
using namespace std;

int bin[128][128];
void divide(int size, int x, int y) {
    if(size == 1){
        cout << bin[x][y];
        return;
    }
    
    bool allsame = true;
    int start = bin[x][y];
    for(int i=x; i<x+size; i++)
        for(int j=y; j<y+size; j++)
            if(bin[i][j] != start)
                allsame = false;
    
    if(allsame)
        cout << start;
    else{
        cout << '(';
        divide(size/2, x, y);
        divide(size/2, x, y+size/2);
        divide(size/2, x+size/2, y);
        divide(size/2, x+size/2, y+size/2);
        cout << ')';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++)
            bin[i][j] = s[j] -'0';
    }
    divide(n, 0, 0);
    return 0;
}
