#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

deque<int> dq;
int skill[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> skill[i];
    
    for(int i=n; i>0; i--){
        if(skill[i] == 1){
            dq.push_front(n+1-i);
        }
        else if(skill[i] == 2){
            int tmp = dq.front();
            dq.pop_front();
            dq.push_front(n+1-i);
            dq.push_front(tmp);
        }
        else if(skill[i] == 3){
            dq.push_back(n+1-i);
        }
    }
    
    while(n--){
        cout << dq.front()<< ' ';
        dq.pop_front();
    }
    return 0;
}
