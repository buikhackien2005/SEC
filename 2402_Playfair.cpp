#include <bits/stdc++.h>
using namespace std;

int main(){
    string p = "Do you want to study a cryptography course";
    char matrix_key[6][6] = {{'M','O','N','A','R','X'},
                             {'C','H','Y','B','D','X'},
                             {'E','F','G','I','K','X'},
                             {'L','P','Q','S','T','X'},
                             {'U','V','W','X','Z','X'},
                             {'X','X','X','X','X','X'}};
    string p_ = "D";
    for(int i = 1; i < p.size(); i++)
        if(p[i] != ' '){
            p_ = p_ + char(p[i] - 32);
        }
    if(p_.size()%2 == 1) p_ = p_ + 'X';
    map <char,pair<int,int>> mp;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            mp[matrix_key[i][j]] = {i,j};
//            cout << mp[matrix_key[i][j]].first;
        }
    mp['J'] = mp['I'];
    string c = "";
    for(int i = 0; i < p_.size(); i += 2){
        char c1 = p_[i];
        char c2 = p_[i + 1];
        int i1 = mp[c1].first; int j1 = mp[c1].second;
        int i2 = mp[c2].first; int j2 = mp[c2].second;
        if(c1 == c2) c = c + c1 + 'X';
        else if(i1 == i2) c = c + matrix_key[i1][j1 + 1] + matrix_key[i2][j2 + 1];
        else if(j1 == j2) c = c + matrix_key[i1 + 1][j1] + matrix_key[i2 + 1][j2];
        else c = c + matrix_key[i1][j2] + matrix_key[i2][j1];
    }
    cout << c;

    return 0;
}
