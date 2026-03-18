#include <bits/stdc++.h>
using namespace std;

bool isLetter(char c){
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    return false;
}

int main(){
    int flag[26] = {0};
    char matrix_key[5][5];
    string keyword;
    string p;

    while(true){
        cout << "\nEnter the keyword (No spaces and special characters, fully capitalized): ";
        getline(cin, keyword);
        if(keyword.find(' ') < keyword.size()){
            cout << "Spaces detected. Please try again!";
            continue;
        }

        //Undercase check
            bool flag_undercase = false;
            for(int i = 0; i < keyword.size(); i++)
                if(keyword[i] >= 'a' && keyword[i] <= 'z'){
                    flag_undercase = true;
                    break;
                }
            if(flag_undercase == true){
                cout << "Undercased letters detected. Please try again!";
                continue;
            }

        //Special characters check
            bool flag_spec = false;
            for(int i = 0; i < keyword.size(); i++)
                if(isLetter(keyword[i]) == false){
                    flag_spec = true;
                    break;
                }
            if(flag_spec == true){
                cout << "Special characters detected. Please try again!";
                continue;
            }

        break;
    }

    cout << "Enter the plaintext: ";
    getline(cin, p);

    //Create the matrix key
    keyword = keyword + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int m = 0, n = 0;
    for(int i = 0; i < keyword.size(); i++){
        if(flag[keyword[i] - 'A'] == 0){
            matrix_key[m][n] = keyword[i];
            n++;
            if(n == 5){
                n = 0;
                m++;
            }
            flag[keyword[i] - 'A'] = 1;
            if(keyword[i] == 'I') flag['J'] = 1;
        }
        else while(flag[keyword[i]] == 1) i++;
    }
//    for(int i = 0; i < 5; i++){
//        for(int j = 0; j < 5; j++)
//            cout << matrix_key[i][j] << ' ';
//        cout << '\n';
//    }

    //Encrypt
    string c = "";
    map<char,pair<int,int>> mp;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            mp[matrix_key[i][j]].first = i;
            mp[matrix_key[i][j]].second = j;
        }
    mp['J'] = mp['I'];
    string p_ = "";
    for(int i = 0; i < p.size(); i++){
        if(p[i] >= 'A' && p[i] <= 'Z') p_ = p_ + p[i];
        else if(p[i] != ' ') p_ = p_ + char(p[i] - 32);
    }
    //cout << p_ << '\n';
    if(p_.size()%2 == 1) p_ = p_ + 'X';
    for(int i = 0; i < p_.size(); i += 2){
        char c1 = p_[i];
        char c2 = p_[i + 1];
        if(c1 == c2){
            c = c + c1 + 'X';
            continue;
        }
        int i1 = mp[c1].first; int j1 = mp[c1].second;
        int i2 = mp[c2].first; int j2 = mp[c2].second;
        c = c + matrix_key[i1%5][j2%5] + matrix_key[i2%5][j1%5];
    }
    cout << "\nPlain text: " << p;
    cout << "\nCipher text: ";
    //Cipher text fully capitalized
    int j = 0; //c index
    for(int i = 0; i < p.size(); i++){
        if(isLetter(p[i])){
            if(p[i] >= 'A' && p[i] <= 'Z') cout << c[j];
            else if(p[i] >= 'a' && p[i] <= 'z') cout << char(c[j] + 32);
            j++;
        }
        else cout << p[i];
    }
}
