#include "VirginiaCode.h"

string VirginiaCode::encrypt(string str, string key) {
    int _pos = 0;   // 正在处理第几个字符
    for (int pos = 0; pos < str.length(); pos++) {
        // 判断是否为字母
        if (isalpha(str[pos])) {
            // 利用同余式计算偏移
            int offset = (key[_pos++ % key.length()] - (isupper(str[pos]) ? 'A' : 'a'));
            congruence(str[pos], offset);
        }
    }
    return str;
}


string VirginiaCode::decode(string str, string key) {
    int _pos = 0;   // 正在处理第几个字符
    for (int pos = 0; pos < str.length(); pos++) {
        // 判断是否为字母
        if (isalpha(str[pos])) {
            // 利用同余式计算偏移
            int offset = (key[_pos++ % key.length()] - (isupper(str[pos]) ? 'A' : 'a'));
            congruence(str[pos], -offset);
        }
    }
    return str;
}



VirginiaCode::VirginiaCode() {

}

VirginiaCode::~VirginiaCode() {

}

void VirginiaCode::fill_key(string& key, int size) {
    while (key.length() < size) {
        key += key;
    }
    if (key.length() > size) {
        key = key.substr(0, size);
    }
}
