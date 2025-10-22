#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    std::string s;
    std::cin >> s;

    // ���ĺ� ���� ī��Ʈ�� ����
    vector<int> count(26, 0);   // ���ĺ� �ε���
    vector<int> chunk(26, 0);   // ���� �ε���

    char prev = '\0'; // ���� ����
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
