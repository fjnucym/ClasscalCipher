#include "customdlg.h"
#include "titlebar.h"
#include <QVBoxLayout>
#include <QPainter>

CustomDlg::CustomDlg(CustomDlg *parent)
{
    // 不要漏了flag的s
        // 设置窗口无边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    m_pTitleBar = new TitleBar(this);
    installEventFilter(m_pTitleBar);
    m_pVBoxLayout = new QVBoxLayout();
    m_pWidget = new QWidget(this);
    m_pVBoxLayout->addWidget(m_pTitleBar);
    m_pVBoxLayout->addWidget(m_pWidget);
    this->setLayout(m_pVBoxLayout);
}


/* 自定义QWidget必须重写QPaintEcent！否则只支持background, background-clip and background-origin 这些属性*/
CustomDlg::~CustomDlg()
{

}

/**将控件加入自定义窗口
 * @brief CustomDlg::addWidgetToDlg
 * @param w 待加入控件
 */
void CustomDlg::addWidgetToDlg(QWidget *w)
{
    w->setParent(m_pWidget);
}

void CustomDlg::setWidgetLayout(QLayout *layout)
{
    m_pWidget->setLayout(layout);
}

void CustomDlg::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}


// 鼠标相对于窗体的位置 event->globalPos() - this->pos()
void CustomDlg::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_point = event->pos();
    }
}

// 若鼠标左键被按下，移动窗体位置
void CustomDlg::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
        move(event->pos() - m_point + pos());
}

// 设置鼠标未被按下
void CustomDlg::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    m_bPressed = false;
}
