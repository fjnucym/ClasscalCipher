#ifndef CUSTOMDLG_H
#define CUSTOMDLG_H

#include <QDialog>
#include <QMouseEvent>
#include <QString>
#include <QStyleOption>

class TitleBar;
class QVBoxLayout;

class CustomDlg : public QDialog
{
    Q_OBJECT
public:
    CustomDlg(CustomDlg *parent = nullptr);
    ~CustomDlg();
    void addWidgetToDlg(QWidget *w);
    void setWidgetLayout(QLayout *layout);


private:
    bool m_bPressed;
    QPoint m_point;
    TitleBar *m_pTitleBar;  // 自定义标题栏
    QVBoxLayout *m_pVBoxLayout;
    QWidget *m_pWidget;


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // CUSTOMDLG_H
