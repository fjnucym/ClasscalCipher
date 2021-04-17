#ifndef CAESARCODE_H
#define CAESARCODE_H

#include <QString>
#include <string>

using namespace std;
class CaesarCode {
public:
    CaesarCode();
    ~CaesarCode();
    static string encrypt(string str, int offset);
    static string decode(string str, int offset);
protected:
    static void congruence(char &ch, int offset, int mod = 26);

};
#endif // CAESARCODE_H
