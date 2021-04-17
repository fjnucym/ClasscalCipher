#include "encryotwidget.h"
#include "caesarcode.h"
#include "virginiacode.h"
#include <QApplication>
#include <QClipboard>
#include <QMessageBox>

#include <QDebug>
EncryotWidget::EncryotWidget()
{
    setFixedSize(800, 600);
    setWindowTitle("古典密码加密");
    initControl();
    initCaesarWidget();
    initVirginiaWidget();
    initLayout();
}

void EncryotWidget::initControl()
{
    m_pComboBox = new QComboBox();
    m_pComboBox->addItem("凯撒密码", QVariant::fromValue(EncryptType::CAESAR));
    m_pComboBox->addItem("维吉尼亚密码", QVariant::fromValue(EncryptType::VIRGINIA));
    connect(m_pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboxCurrentIndexChanged(int)));


    m_pBeforeLab = new QLabel("转换前:");
    m_pAfterLab = new QLabel("转换后:");
    m_pEncrytEdit = new QPlainTextEdit();
    connect(m_pEncrytEdit, SIGNAL(textChanged()), SLOT(checkWord()));


    m_pDecodeEdit = new QPlainTextEdit();
    m_pDecodeEdit->setFocusPolicy(Qt::NoFocus);
    m_pEncryptBtn = new QPushButton("加密");
    connect(m_pEncryptBtn, SIGNAL(clicked()), this, SLOT(on_encryptBtn_clicked()));
    m_pDecodeBtn = new QPushButton("解密");
    connect(m_pDecodeBtn, SIGNAL(clicked()), this, SLOT(on_decodeBtn_clicked()));
    m_pCopyBtn = new QPushButton("复制");
    connect(m_pCopyBtn, SIGNAL(clicked()), this, SLOT(copyCode()));
}

void EncryotWidget::initLayout()
{
    m_pGridLayout = new QGridLayout();
    setWidgetLayout(m_pGridLayout);

    m_pGridLayout->addWidget(m_pBeforeLab, 1, 0, 1, 1);
    m_pGridLayout->addWidget(m_pEncrytEdit, 2, 0, 4, 11);
    m_pGridLayout->addWidget(m_pComboBox, 6, 0, 1, 2);
    m_pGridLayout->addWidget(m_pCaesarWidget, 6, 2, 1, 4);
    m_pGridLayout->addWidget(m_pVirginiaWidget, 6, 2, 1, 4);
    m_pGridLayout->addWidget(m_pEncryptBtn, 6, 6, 1, 1);
    m_pGridLayout->addWidget(m_pDecodeBtn, 6, 7, 1, 1);
    m_pGridLayout->addWidget(m_pCopyBtn, 6, 8, 1, 1);
    m_pGridLayout->addWidget(m_pAfterLab, 7, 0, 1, 1);
    m_pGridLayout->addWidget(m_pDecodeEdit, 8, 0, 4, 11);

    m_pGridLayout->addWidget(new QLabel("姓名:陈一鸣 学号:116132019148\n指导老师:宁建廷"));
}

void EncryotWidget::initCaesarWidget()
{
    m_pCaesarWidget = new QWidget();
    QHBoxLayout *pCaesar_HBoxLayout = new QHBoxLayout();
    m_pCaesarWidget->setLayout(pCaesar_HBoxLayout);
    m_pCaesarEdit = new QLineEdit();
    pCaesar_HBoxLayout->addWidget(new QLabel("加密位移:"));
    pCaesar_HBoxLayout->addWidget(m_pCaesarEdit);
    m_pCurrentShowWidget = m_pCaesarWidget;
}

void EncryotWidget::initVirginiaWidget()
{
    m_pVirginiaWidget = new QWidget();
    QHBoxLayout *pVirginia_HBoxLayout = new QHBoxLayout();
    m_pVirginiaWidget->setLayout(pVirginia_HBoxLayout);
    m_pVirginiaEdit = new QLineEdit();
    pVirginia_HBoxLayout->addWidget(new QLabel("密钥:"));
    pVirginia_HBoxLayout->addWidget(m_pVirginiaEdit);
    m_pVirginiaWidget->hide();
}

void EncryotWidget::comboxCurrentIndexChanged(int index)
{
    Q_UNUSED(index);
    EncryptType type = m_pComboBox->currentData().value<EncryptType>();
    switch(type){
    case EncryptType::CAESAR:
        m_pCurrentShowWidget->hide();
        m_pCaesarWidget->show();
        m_pCurrentShowWidget = m_pCaesarWidget;
        break;
    case EncryptType::VIRGINIA:
        m_pCurrentShowWidget->hide();
        m_pVirginiaWidget->show();
        m_pCurrentShowWidget = m_pVirginiaWidget;
        break;
    }
}

void EncryotWidget::on_encryptBtn_clicked()
{
    // 获取当前加密类型
    EncryptType type = m_pComboBox->currentData().value<EncryptType>();
    switch(type){
    case EncryptType::CAESAR:
        m_pDecodeEdit->setPlainText(
                    QString::fromStdString(
                        CaesarCode::encrypt(m_pEncrytEdit->toPlainText().toStdString(),
                                           m_pCaesarEdit->text().toInt())
                        )
                    );
        break;
    case EncryptType::VIRGINIA:
        m_pDecodeEdit->setPlainText(
                    QString::fromStdString(
                        VirginiaCode::encrypt(m_pEncrytEdit->toPlainText().toStdString(),
                                              m_pVirginiaEdit->text().toStdString()
                                              )
                        )
                    );
        break;
    }
}

void EncryotWidget::on_decodeBtn_clicked()
{
    // 获取当前加密类型
    EncryptType type = m_pComboBox->currentData().value<EncryptType>();
    switch(type){
    case EncryptType::CAESAR:
        m_pDecodeEdit->setPlainText(
                    QString::fromStdString(
                        CaesarCode::decode(m_pEncrytEdit->toPlainText().toStdString(),
                                           m_pCaesarEdit->text().toInt())
                        )
                    );
        break;
    case EncryptType::VIRGINIA:
        m_pDecodeEdit->setPlainText(
                    QString::fromStdString(
                        VirginiaCode::decode(m_pEncrytEdit->toPlainText().toStdString(),
                                              m_pVirginiaEdit->text().toStdString())
                        )
                    );
        break;
    }
}

void EncryotWidget::checkWord()
{
    // 设置账户正则
    QRegExp accExp("[a-zA-Z]*");

}

void EncryotWidget::copyCode()
{

    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    QString originalText = clipboard->text();	     //获取剪贴板上文本信息
    clipboard->setText(m_pDecodeEdit->toPlainText());
    QMessageBox::information(this, "提示", "复制成功");
}


