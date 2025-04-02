#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Authentification - ELICAR");





    // Charger et vérifier l'image de l'icône de l'application
    QPixmap pixmap("C:/Users/Admin/Desktop/projet/images/logo.png");
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }

    // Charger et afficher l'image du login
    QPixmap loginPixmap("C:/Users/Admin/Desktop/projet/images/login.png");
    if (!loginPixmap.isNull()) {
        ui->labelImage->setPixmap(loginPixmap.scaled(100, 100, Qt::KeepAspectRatio));
        ui->labelImage->setAlignment(Qt::AlignCenter);
    } else {
        qDebug() << "L'image pour le login n'a pas pu être chargée!";
    }



    // Positionnement
    ui->loginWidget->setGeometry(510, 40, ui->loginWidget->width(), ui->loginWidget->height());
    ui->widget_logo->setGeometry(40, 10, ui->widget_logo->width(), ui->widget_logo->height());

    // Masquage initial
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetRei->setVisible(false);

    // Configuration champs
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    //  ui->lineEditUsername->setPlaceholderText("Nom d'utilisateur");
    ui->lineEditPassword->setPlaceholderText("Mot de passe");
}


void login::on_btnConnecter_clicked()
{
    QString username = ui->lineEditEmail->text().trimmed();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs");
        return;
    }

    if (authenticate(username, password)) {
        emit loginSuccess();
    } else {
        QMessageBox::critical(this, "Erreur", "Identifiants incorrects");
        ui->lineEditPassword->clear();
        ui->lineEditEmail->setFocus();
    }
}

bool login::authenticate(const QString &username, const QString &password)
{
    // Exemple simple - À remplacer par votre logique d'authentification
    return (username == "admin" && password == "admin123");
}

void login::on_btnMotDePasse_clicked()
{
    ui->loginWidget->setVisible(false);
    ui->widgetRei->setVisible(false);
    ui->mot_de_passe_oublie->setGeometry(ui->loginWidget->geometry());
    ui->mot_de_passe_oublie->setVisible(true);
}

void login::on_btnquestion_clicked()
{
    ui->loginWidget->setVisible(false);
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetRei->setGeometry(ui->loginWidget->geometry());
    ui->widgetRei->setVisible(true);
}



void login::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap bgPixmap("C:/Users/Admin/Desktop/projet/images/back3.png");

    if (!bgPixmap.isNull()) {
        painter.drawPixmap(0, 0, bgPixmap);
    } else {
        qDebug() << "L'image d'arrière-plan n'a pas pu être chargée!";
    }
}

login::~login()
{
    delete ui;
}
