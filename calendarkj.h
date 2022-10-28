#ifndef CALENDARKJ_H
#define CALENDARKJ_H
#include <QCalendarWidget>
#include <QLocale>
#include <QPainter>
#include <QTextCharFormat>
#include <QProxyStyle>
#include <QTableView>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
class QPushButton;
class QLabel;

class calendarKJ : public QCalendarWidget
{
    Q_OBJECT
public:
    calendarKJ(QWidget *parent);
    ~calendarKJ();
private:
    void initControl();
    void initTopWidget();
    void initBottomWidget();
    void setDataLabelTimeText(int year, int month);

signals:
    void signalSetCalendarTime(const QDate& data);

private slots:
    void onbtnClicked();
    void btnEnsureClicked();

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    QPushButton* m_leftYearBtn;
    QPushButton* m_leftMonthBtn;
    QPushButton* m_rightYearBtn;
    QPushButton* m_rightMonthBtn;
    QPushButton* m_ensureBtn;
    QPushButton* m_toDayBtn;

    QLabel* m_dataLabel;
    int m_month;            //界面切换到的月份

};



#endif // CALENDARKJ_H
