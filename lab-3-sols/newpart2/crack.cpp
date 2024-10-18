#include <iostream>
#include <algorithm>
#include "hash.h"
using namespace std;

string crackOne(size_t hash) {
    string ans = "";
    while (hash > 0) {
        int v = hash % 256;
        ans += (char)v;
        hash = (hash - v) / 256;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string crackTwo(size_t hash) {
    string ans = "";
    while (hash > 'z') {
        ans += 'z';
        hash -= 'z';
    }
    ans += (char)(hash);
    return ans;
}

bool isAlphaNumeric(const string &str) {
    return find_if(str.begin(), str.end(), [](char const &c)
                   { return !isalnum(c) && !(c == '!' || c == ' ' || c == ','); }) == str.end();
}

string crackThree(size_t hash, bool check) {
    int M = 33;
    if (hash == 5381) {
        return "";
    }
    for (char c = 127; c > -1; c--) {
        if (!isalnum(c) && !(c == '!' || c == ' ' || c == ',')) {
            continue;
        }
        if (hash >= c && (hash - c) % M == 0) {
            string s = crackThree((hash - c) / M, 0);
            if (find(s.begin(), s.end(), '#') != s.end())
            {
                continue;
            }
            return s + c;
        }
    }
    return "#";
}

string crackFour(size_t hash, bool check) {
    int M = 17;
    if (hash == 5381) {
        return "";
    }
    for (char c = 127; c > -1; c--) {
        if (!isalnum(c) && !(c == '!' || c == ' ' || c == ',')) {
            continue;
        }
        if (hash >= c && (hash - c) % M == 0) {
            string s = crackFour((hash - c) / M, 0);
            if (find(s.begin(), s.end(), '#') != s.end()) {
                continue;
            }
            return s + c;
        }
    }
    return "#";
}

string crackFive(size_t hash) {
    if (hash == 5381) {
        return "";
    }
    else if (hash < 5381) {
        return "#";
    }
    for (char c = 127; c > 2; c--)
    {
        if (!isalnum(c) && !(c == '!' || c == ' ' || c == ',')) {
            continue;
        }
        if (hash % c == 0) {
            string s = crackFive(hash / c - 1);
            if (find(s.begin(),s.end(),'#') != s.end()) {
                continue;
            }
            if (isAlphaNumeric(s + c)) {
                return s + c;
            }
        }
    }
    return "#";
}

string crackSix(size_t hash) {
    string ans = "", S = to_string(hash);
    int num = 0;
    for (int i = 0; i < S.size(); i++) {
        num = num * 10 + (S[i] - '0');
        if (num >= ' ' && num <= 'z') {
            ans += (char)num;
            num = 0;
        }
    }
    return ans;
}

int main (int argc, char* argv[]) {
    size_t hash;
    string ans, hint;
    int choice;
    cin >> choice;
    if (choice == 1) {
        hash = PASSWORD_HASH_ONE;
        ans = "Password: \"" + crackOne(hash) + "\"";
        hint = "Hint: polynomials";
    }
    else if (choice == 2) {
        hash = PASSWORD_HASH_TWO;
        ans = "Password: \"" + crackTwo(hash) + "\"";
        hint = "Hint: sum";
    }
    else if (choice == 3) {
        hash = PASSWORD_HASH_THREE;
        ans = "Password: \"" + crackThree(hash,1) + "\"";
        hint = "Hint: monotonic";
    }
    else if (choice == 4) {
        hash = PASSWORD_HASH_FOUR;
        ans = "Password: \"" + crackFour(hash, 1) + "\"";
        hint = "Hint: sum";
    }
    else if (choice == 5) {
        hash = PASSWORD_HASH_FIVE;
        ans = "Password: \"" + crackFive(hash) + "\"";
        hint = "Hint: factorization";
    }
    else if (choice == 6) {
        hash = PASSWORD_HASH_SIX;
        ans = "Password: \"" + crackSix(hash) + "\"";
        hint = "Hint: ascii";
    }
    cout << hint << endl
         << ans << endl;
}
