#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
void bfs(){
    queue<pair<int, string>> q;
    vector<bool> visited(10000, 0);
    q.push({a, ""});
    visited[a] = true;

    while(!q.empty()){
        int now = q.front().first;
        string com = q.front().second;
        q.pop();
        
        if(now == b){
            cout << com << '\n';
            return;
        }
        
        int next;
        //D
        next = (now * 2) % 10000;
        if(!visited[next]){
            visited[next] = true;
            q.push({next, com+"D"});
        }
        //S
        next = now==0? 9999:now-1;
        if(!visited[next]){
            visited[next] = true;
            q.push({next, com+"S"});
        }
        //L
        next = (now%1000)*10 + now/1000;
        if(!visited[next]){
            visited[next] = true;
            q.push({next, com+"L"});
        }
        //R
        next = (now%10)*1000 + now/10;
        if(!visited[next]){
            visited[next] = true;
            q.push({next, com+"R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        bfs();
    }
    return 0;
}
