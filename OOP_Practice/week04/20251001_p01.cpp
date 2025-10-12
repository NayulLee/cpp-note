#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    std::string s;
    std::cin >> s;

    // 알파벳 개수 카운트용 벡터
    vector<int> count(26, 0);   // 알파벳 인덱스
    vector<int> chunk(26, 0);   // 묶음 인덱스

    char prev = '\0'; // 직전 문자
    for (char c : s) {
        int idx = c - 'a';
        count[idx]++;    

        if (c != prev) {
            chunk[idx]++;
        }

        prev = c;
    }

    string result = "";
    for (int i = 0; i < 26; i++) 
    {
        if (count[i] >= 2 && chunk[i] >= 2) {
            result += (char)('a' + i);
        }
    }

    if (result.empty()) 
    {
        cout << "N" << endl;
    }
    else 
    {
        cout << result << endl;
    }

    return 0;
}
