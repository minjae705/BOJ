#include <iostream>
using namespace std;

int n, ans;
int queen[16];
void recursion(int idx) {
    if(idx == n){
        ans++;
        return;
    }
    
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=0; j<idx; j++){
            if(i == queen[j] || abs(i-queen[j]) == idx-j){ //j번째 줄 i번째 칸에 퀸 배치가 가능한지
                flag = false;
                break;
            }
        }
        
        if(flag){
            queen[idx] = i;
            recursion(idx+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    recursion(0);
    cout << ans << '\n';
    return 0;
}
