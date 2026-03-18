#include <bits/stdc++.h>
using namespace std;

char key_array[100];

int main(){
    int cont = 0;
    string plaintext, key, encodedtext;
    while(true){
        memset(key_array, 0, 100);
        plaintext.clear(); key.clear(); encodedtext.clear();
        cout << "Plain text: ";
        if(cont == 1) cin.ignore();
        getline(cin, plaintext);
        cout << "Key: ";
        cin >> key;
        int k = key.size();
        for(int i = 0; i < k; i++)
            key_array[i] = key[i];
        key.clear();
        int n = 0, i = 0;
        while(n < plaintext.size()){
            if(plaintext[n] >= 'A' && plaintext[n] <= 'Z'){
                key = key + key_array[i%k];
                i++;
            }
            else key = key + ' ';
            n++;
        }
        for(int i = 0; i < n; i++)
            if(plaintext[i] != ' ') encodedtext = encodedtext + char(((plaintext[i] - 'A') + (key[i] - 'A'))%26 + 'A');
            else encodedtext = encodedtext + ' ';
        cout << "Encoded Text: " << encodedtext << '\n';

        cout << "Continue? (0 for No, 1 for Yes)\n";
        cin >> cont;
        if(cont == 0) return 0;
    }

    return 0;
}

