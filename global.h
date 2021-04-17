#ifndef GLOBAL_H
#define GLOBAL_H
#include <QVariant>
enum class EncryptType{
    CAESAR = 0,     // 凯撒密码
    VIRGINIA = 1    // 维吉尼亚密码
};

Q_DECLARE_METATYPE(EncryptType);

#endif // GLOBAL_H
