#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
signals:
    void loginSuccess();

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_btnConnecter_clicked();
    void on_btnMotDePasse_clicked();
    void on_btnquestion_clicked();


private:
    Ui::login *ui;

    bool authenticate(const QString &username, const QString &password);
};

#endif // LOGIN_H
