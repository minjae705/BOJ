#include <iostream>
using namespace std;

int pap[3333][3333];
int cnt[3]; // -1 0 1
void divide(int size, int x, int y) {
    if(size == 1){
        cnt[pap[x][y] + 1]++;
        return;
    }
    
    bool allsame = true;
    int start = pap[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
                if(pap[i][j] != start)
                    allsame = false;
        }
    }
    
    if(allsame)
        cnt[start + 1]++;
    else{
        divide(size/3, x, y);
        divide(size/3, x+size/3, y);
        divide(size/3, x+size/3*2, y);
        divide(size/3, x, y+size/3);
        divide(size/3, x+size/3, y+size/3);
        divide(size/3, x+size/3*2, y+size/3);
        divide(size/3, x, y+size/3*2);
        divide(size/3, x+size/3, y+size/3*2);
        divide(size/3, x+size/3*2, y+size/3*2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> pap[i][j];
    
    divide(n, 0, 0);
    for(int i=0;i<3;i++)
        cout << cnt[i] << '\n';
    return 0;
}
