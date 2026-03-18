
#include <bits/stdc++.h>
using namespace std;

char key_array[100];

int main(){
    int cont = 0;
    string plaintext, key, encodedtext;
    while(true){
        memset(key_array, 0, 100);
        plaintext.clear(); key.clear(); encodedtext.clear();
        cout << "Encoded Text: ";
        if(cont == 1) cin.ignore();
        getline(cin, encodedtext);
        cout << "Key: ";
        cin >> key;
        for(int i = 0; i < key.size(); i++)
            key_array[i] = key[i];
        int k = key.size(), n = 0, i = 0;
        key.clear();
        while(n < encodedtext.size()){
            if(encodedtext[n] >= 'A' && encodedtext[n] <= 'Z'){
                key = key + key_array[i%k];
                i++;
            }
            else key = key + ' ';
            n++;
        }
        for(int j = 0; j < key.size(); j++){
            if(key[j] != ' ') plaintext = plaintext + char((((encodedtext[j] - 'A') - (key[j] - 'A')) + 26)%26 + 'A');
            else plaintext = plaintext + ' ';
        }
        cout << "Plain text: " << plaintext << '\n';

        cout << "Continue? (0 for No, 1 for Yes)\n";
        cin >> cont;
        if(cont == 0) return 0;
    }

    return 0;
}
