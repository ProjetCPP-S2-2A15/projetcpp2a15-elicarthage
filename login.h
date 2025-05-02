#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QWidget>
#include <QIcon>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
     explicit login(MainWindow* mainWindow, QWidget *parent = nullptr);
    void clearInterface();
     void setupPasswordVisibilityToggle();
     void togglePasswordVisibility(QLineEdit* lineEdit, QPushButton* button);

    ~login();
signals:
   // void loginSuccess();
        void loginSuccess(const QString &role);

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_btnConnecter_clicked();
    void on_btnMotDePasse_clicked();
    void on_btnquestion_clicked();

   void on_btnValider_clicked();


       void on_btnReinitialiser_clicked();

   void on_btnRetour_clicked();
private:
    Ui::login *ui;
     MainWindow* m_mainWindow;
 QString m_role;
    bool verifierReponse(const QString &email, const QString &reponseUtilisateur);

    bool authenticate(const QString &username, const QString &password);

};

#endif // LOGIN_H
