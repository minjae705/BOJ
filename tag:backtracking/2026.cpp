#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, f;
bool student[909][909];
bool join[909];
int friendcnt[909]; 
int joinnum;
vector<int> members;

bool check(int i){
    for(int mem:members)
        if(!student[mem][i])
            return false;
    return true;
}

void solve(int cur){
    if(cur == n) return;
    if(joinnum == k){
        for(int mem:members)
            cout << mem << '\n';
        exit(0);
    }
    
    for(int i=1;i<=n;i++){
        if(friendcnt[i]<k-1) continue; //처음엔 이 조건이 없어서 시간초과 났음
        if(join[i]) continue;
        if(!check(i)) continue;
        
        join[i] = true;
        members.push_back(i);
        joinnum++;
        
        solve(cur+1);
        
        join[i] = false;
        members.pop_back();
        joinnum--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> k >> n >> f;
    int a, b;
    for(int i=0;i<f;i++){
        cin >> a >> b;
        student[a][b] = true;
        student[b][a] = true;
        friendcnt[a]++;
        friendcnt[b]++;
    }
    
    solve(0);
    cout << -1;
    return 0;
}
