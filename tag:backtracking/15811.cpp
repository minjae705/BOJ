#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string bms[3]; //문자열 입력
bool alpha[26]; //등장한 알파벳인지 확인
vector<int> v; //중복없이 등장한 알파벳 저장
int altonum[26]; //알파벳에 할당된 숫자
bool numused[10]; //사용된 숫자인지 확인

void solve(int cur){
    if(cur == v.size()){
        long long resnum[3] = {0, 0, 0};
        for(int i=0;i<3;i++){
            for(int j=0;j<bms[i].length();j++){
                resnum[i] *= 10;
                resnum[i] += altonum[bms[i][j]-'A'];
            }
        }
        
        if(resnum[0] + resnum[1] == resnum[2]){
            cout << "YES";
            exit(0);
        }
        return;
    }
    
    int idx = v[cur];
    for(int i=0;i<=9;i++){
        if(numused[i]) continue; //이미 할당된 숫자라면 패스
        altonum[idx] = i; //알파벳에 숫자 할당
        numused[i] = true; //숫자가 할당되었음
        solve(cur + 1); // 다음 알파벳에 할당 시도
        
        // 할당 취소
        numused[i] = false;
        altonum[idx] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0;i<3;i++){
        cin>>bms[i];
        for(int j=0;j<bms[i].length();j++){
            int k = bms[i][j] - 'A';
            if(!alpha[k]){
                alpha[k] = true;
                v.push_back(k);
            }
        }
    }
    
    if(v.size() <= 10)
        solve(0);

    cout << "NO";
    
    return 0;
}
