#ifndef CHATITEMWIDGET_H
#define CHATITEMWIDGET_H

#include <QWidget>
#include<QDateTime>

//у сообщения есть время и положение (слева или справа)
namespace Ui {
class ChatItemWidget;
}

class ChatItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatItemWidget(QWidget *parent = nullptr);
    ~ChatItemWidget();
    void setMessage(QString message, bool isMyMessage = false);

private:
    Ui::ChatItemWidget *ui;
};

#endif // CHATITEMWIDGET_H
