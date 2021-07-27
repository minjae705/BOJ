#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

string start="", target="123456780";

void bfs() {
    queue<pair<string, int>> q;
    set<string> visit;

    q.push({start, 0});
    visit.insert(start);
    
    while(!q.empty()){
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(str == target){
            cout << cnt;
            return;
        }

        int now, nxt;
        now = (int)str.find('0');
        string tmp;
        
        nxt = now + 1;
        tmp = str;
        swap(tmp[now], tmp[nxt]);
        if(visit.find(tmp) == visit.end() && now%3!=2){
            visit.insert(tmp);
            q.push({tmp, cnt+1});
        }

        nxt = now - 1;
        tmp = str;
        swap(tmp[now], tmp[nxt]);
        if(visit.find(tmp) == visit.end() && now%3!=0){
            visit.insert(tmp);
            q.push({tmp, cnt+1});
        }

        nxt = now + 3;
        tmp = str;
        swap(tmp[now], tmp[nxt]);
        if(visit.find(tmp) == visit.end() && now<=5){
            visit.insert(tmp);
            q.push({tmp, cnt+1});
        }

        nxt = now - 3;
        tmp = str;
        swap(tmp[now], tmp[nxt]);
        if(visit.find(tmp) == visit.end() && now>=3){
            visit.insert(tmp);
            q.push({tmp, cnt+1});
        }
    }

    cout << -1;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tmp;
    for(int i=0;i<9;i++){
        cin >> tmp;
        start += tmp + '0';
    }
    
    bfs();
    
    return 0;
}
