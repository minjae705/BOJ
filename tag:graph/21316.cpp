#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;
vector<int> v[13];
int main(){
    int a, b;
    for(int i=0; i<12; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=12; i++){
        int tmp=0;
        if(v[i].size() == 3){
            tmp = v[v[i][0]].size() + v[v[i][1]].size() + v[v[i][2]].size();
            if(tmp == 6)
                ans = i;
        }
    }
    cout << ans;
}
