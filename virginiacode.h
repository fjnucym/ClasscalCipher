#ifndef VIRGINIACODE_H
#define VIRGINIACODE_H
#include <string>
#include <iostream>

#include "CaesarCode.h"

using namespace std;

class VirginiaCode
    : public CaesarCode
{
public:
    VirginiaCode();
    ~VirginiaCode();
    static string encrypt(string str, string key);
    static string decode(string str, string key);
    static void fill_key(string& key, int size);

};
#endif // VIRGINIACODE_H
