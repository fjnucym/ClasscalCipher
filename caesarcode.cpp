#include "CaesarCode.h"


CaesarCode::CaesarCode() {
}

CaesarCode::~CaesarCode() {
}


string CaesarCode::encrypt(string str, int offset) {
    if (offset < 0) {
        return "格式不正确";
    }
    for (int pos = 0; pos < str.length(); pos++) {
        if(isalpha(str[pos])){
            congruence(str[pos], offset);
        }
    }
    return str;
}

string CaesarCode::decode(string str, int offset) {
    if (offset < 0) {
        return "格式不正确";
    }
    for (int pos = 0; pos < str.length(); pos++) {
        if(isalpha(str[pos])){
            congruence(str[pos], -offset);
        }
    }
    return str;
}

void CaesarCode::congruence(char& ch, int offset, int mod) {
    char temp = ch - (isupper(ch) ? 'A' : 'a');
    temp = (temp + offset) % mod;
    temp = temp >= 0 ? temp : mod + temp;
    ch = temp + (isupper(ch) ? 'A' : 'a');
}


