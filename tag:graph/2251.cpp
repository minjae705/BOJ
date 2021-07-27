#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool visited[202][202][202];
int a, b, c;

void dfs(int i, int j, int k){
    visited[i][j][k] = true;
    if(i==0)
        v.push_back(k);
    
    if(!visited[max(i+j-b, 0)][min(i+j, b)][k])
        dfs(max(i+j-b, 0), min(i+j, b), k); //i-j
    
    if(!visited[max(i+k-c, 0)][j][min(i+k, c)])
        dfs(max(i+k-c, 0), j, min(i+k, c)); //i-k
    
    if(!visited[min(i+j, a)][max(j+i-a, 0)][k])
        dfs(min(i+j, a), max(i+j-a, 0), k); //j-i
    
    if(!visited[i][max(j+k-c, 0)][min(j+k, c)])
        dfs(i, max(i+k-c, 0), min(j+k, c)); //j-k
    
    if(!visited[min(k+i, a)][j][max(k+i-a, 0)])
        dfs(min(k+i, a), j, max(k+i-a, 0)); //k-i
    
    if(!visited[i][min(k+j, b)][max(k+j-b, 0)])
        dfs(i, min(k+j, b), max(k+j-b, 0)); //k-j
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a >> b >> c;
    dfs(0, 0, c);
    
    sort(v.begin(), v.end());
    for(auto x:v)
        cout << x << ' ';
    
    return 0;
}
