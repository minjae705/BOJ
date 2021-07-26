#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ary[12];
vector<int> oper;
int maxnum = -98765432, minnum = 98765432;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> ary[i];
    for(int i=0;i<4;i++){
        int tmp;
        cin >> tmp;
        while(tmp--) oper.push_back(i);
    }
    
    do{
        int res = ary[0];
        for(int i=0;i<n-1;i++){
            if(oper[i]==0) res+=ary[i+1];
            if(oper[i]==1) res-=ary[i+1];
            if(oper[i]==2) res*=ary[i+1];
            if(oper[i]==3) res/=ary[i+1];
        }
        maxnum = max(maxnum, res);
        minnum = min(minnum, res);
    }while(next_permutation(oper.begin(), oper.end()));
    
    cout << maxnum << '\n' << minnum << '\n';
    return 0;
}
