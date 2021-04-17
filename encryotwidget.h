#ifndef ENCRYOTWIDGET_H
#define ENCRYOTWIDGET_H

#include <QObject>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QList>
#include "global.h"
#include "customdlg.h"


class EncryotWidget : public CustomDlg
{
    Q_OBJECT
public:
    EncryotWidget();

private:
    QGridLayout *m_pGridLayout;
    QPlainTextEdit *m_pEncrytEdit;
    QPlainTextEdit *m_pDecodeEdit;
    QComboBox *m_pComboBox;
    QLabel *m_pTitleLab;
    QLabel *m_pTipLab;

    QPushButton *m_pEncryptBtn;
    QPushButton *m_pDecodeBtn;
    QPushButton *m_pCopyBtn;
    QLabel *m_pBeforeLab;
    QLabel *m_pAfterLab;

    QWidget *m_pCaesarWidget;
    QLineEdit *m_pCaesarEdit;

    QWidget *m_pVirginiaWidget;
    QLineEdit *m_pVirginiaEdit;

    QWidget *m_pCurrentShowWidget;

private:
    void initControl();
    void initLayout();
    void initCaesarWidget();
    void initVirginiaWidget();

private slots:
    void comboxCurrentIndexChanged(int index);
    void on_encryptBtn_clicked();
    void on_decodeBtn_clicked();
    void checkWord();
    void copyCode();
};

#endif // ENCRYOTWIDGET_H
