#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include "mainwindow.h"
#include "architecte.h"
login::login(MainWindow* mainWindow, QWidget *parent)
    : QWidget(parent), ui(new Ui::login), m_mainWindow(mainWindow)
{
    ui->setupUi(this);
    ui->btnRetour->move(590,420); // Position souhaitée
    ui->btnRetour->setVisible(false);
    ui->loginWidget->setVisible(true);  // Seul le widget de login visible au départ
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetQuestion->setVisible(false);  // Assurez-vous que ce nom correspond à votre UI
    ui->widgetRei->setVisible(false);


    this->setWindowTitle("Authentification - ELICAR");
    connect(ui->btnRetour, &QPushButton::clicked, this, &login::on_btnRetour_clicked);
    QPixmap pixmap("C:/Users/Admin/Desktop/projet/images/logo.png");
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }


    // Positionnement
    ui->loginWidget->setGeometry(510, 40, ui->loginWidget->width(), ui->loginWidget->height());
    ui->widget_logo->setGeometry(40, 10, ui->widget_logo->width(), ui->widget_logo->height());

    // Masquage initial
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetRei->setVisible(false);

    // Configuration champs
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    ui->lineEditPassword->setPlaceholderText("Mot de passe");


    connect(ui->nvPass, &QLineEdit::textChanged, this, [this](const QString &text) {
        if (m_mainWindow) {
            m_mainWindow->verifierMotDePasse(text, ui->labelErreur);
        }
    });
    setupPasswordVisibilityToggle();

}


void login::setupPasswordVisibilityToggle() {
    // Créer les boutons œil
    QPushButton *togglePasswordButton = new QPushButton(ui->lineEditPassword);
    QPushButton *toggleNvPassButton = new QPushButton(ui->nvPass);
    QPushButton *toggleConfirmPassButton = new QPushButton(ui->confirmPass);

    // Configurer les boutons
    for (auto button : {togglePasswordButton, toggleNvPassButton, toggleConfirmPassButton}) {
        button->setCursor(Qt::PointingHandCursor);
        button->setIcon(QIcon("C:/Users/Admin/Desktop/projet/images/eye_closed.png")); // Chemin vers votre image œil fermé
        button->setStyleSheet("border: none; padding: 0px; background: transparent;");
        button->setFixedSize(24, 24);
    }

    // Positionner les boutons
    togglePasswordButton->move(ui->lineEditPassword->width() - 30, (ui->lineEditPassword->height() - 24) / 2);
    toggleNvPassButton->move(ui->nvPass->width() - 30, (ui->nvPass->height() - 24) / 2);
    toggleConfirmPassButton->move(ui->confirmPass->width() - 30, (ui->confirmPass->height() - 24) / 2);

    // Connecter les signaux
    connect(togglePasswordButton, &QPushButton::clicked, this, [this, togglePasswordButton]() {
        togglePasswordVisibility(ui->lineEditPassword, togglePasswordButton);
    });

    connect(toggleNvPassButton, &QPushButton::clicked, this, [this, toggleNvPassButton]() {
        togglePasswordVisibility(ui->nvPass, toggleNvPassButton);
    });

    connect(toggleConfirmPassButton, &QPushButton::clicked, this, [this, toggleConfirmPassButton]() {
        togglePasswordVisibility(ui->confirmPass, toggleConfirmPassButton);
    });

    // S'assurer que les boutons restent visibles quand le texte change
    connect(ui->lineEditPassword, &QLineEdit::textChanged, [togglePasswordButton, this]() {
        togglePasswordButton->move(ui->lineEditPassword->width() - 30, (ui->lineEditPassword->height() - 24) / 2);
    });

    connect(ui->nvPass, &QLineEdit::textChanged, [toggleNvPassButton, this]() {
        toggleNvPassButton->move(ui->nvPass->width() - 30, (ui->nvPass->height() - 24) / 2);
    });

    connect(ui->confirmPass, &QLineEdit::textChanged, [toggleConfirmPassButton, this]() {
        toggleConfirmPassButton->move(ui->confirmPass->width() - 30, (ui->confirmPass->height() - 24) / 2);
    });
}


// Ajouter cette méthode à votre classe login
void login::togglePasswordVisibility(QLineEdit* lineEdit, QPushButton* button) {
    if (lineEdit->echoMode() == QLineEdit::Password) {
        lineEdit->setEchoMode(QLineEdit::Normal);
        button->setIcon(QIcon("C:/Users/Admin/Desktop/projet/images/eye_open.png")); // Chemin vers votre image œil ouvert
    } else {
        lineEdit->setEchoMode(QLineEdit::Password);
        button->setIcon(QIcon("C:/Users/Admin/Desktop/projet/images/eye_closed.png")); // Chemin vers votre image œil fermé
    }
}

// Dans le constructeur login::login(), ajoutez cet appel après la configuration des QLineEdit



void login::on_btnValider_clicked()
{
    QString email = ui->lineEditemailR->text().trimmed();

    // Vérification email vide
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email");
        return;
    }

    // Vérification existence email
    Architecte A; // Créez une instance d'Architecte
    if (!A.emailExists(email)) {
        QMessageBox::critical(this, "Erreur", "Email non trouvé. Veuillez vérifier votre email.");
        ui->lineEditemailR->clear();
        ui->lineEditemailR->setFocus();
        return;
    }

    // Si l'email existe, afficher le widget suivant et récupérer la question
    QSqlQuery query;
    query.prepare("SELECT QUESTION FROM ZEINEB.ARCHITECTE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        // Afficher la question dans le widget suivant
        ui->question->setText(query.value(0).toString());

        // Passer au widget suivant
        ui->mot_de_passe_oublie->setVisible(false);
        ui->widgetQuestion->setVisible(true);
        ui->btnRetour->setVisible(true); // Afficher le bouton
        ui->btnRetour->move(590,420);
        ui->widgetQuestion->setGeometry(ui->loginWidget->geometry());
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer la question associée à cet email");
    }
}

bool login::verifierReponse(const QString &email, const QString &reponseUtilisateur)
{
    QSqlQuery query;
    query.prepare("SELECT REponse FROM ZEINEB.ARCHITECTE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer la réponse secrète.");
        return false;
    }

    QString reponseCorrecte = query.value(0).toString().trimmed().toLower();
    QString reponseEntree = reponseUtilisateur.trimmed().toLower();

    return reponseCorrecte == reponseEntree;
}
//------------------------------------------------------------------------------------------------------
void login::on_btnquestion_clicked()
{


    QString email = ui->lineEditemailR->text().trimmed();
    QString reponseUtilisateur = ui->lineEditReponse->text().trimmed();

    if (/*email.isEmpty() ||*/ reponseUtilisateur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");

        return;
    }

    if (verifierReponse(email, reponseUtilisateur)) {
        ui->widgetQuestion->setVisible(false);
        ui->widgetRei->setVisible(true);
        ui->btnRetour->setVisible(true); // Afficher le bouton
        ui->btnRetour->move(590,420);
        ui->widgetRei->setGeometry(ui->loginWidget->geometry());
    } else {
        QMessageBox::critical(this, "Erreur", "Réponse incorrecte. Veuillez vérifier votre réponse !");
        ui->lineEditReponse->clear();
        ui->lineEditReponse->setFocus();
    }

    // Réactiver le bouton après traitement

}
//----------------------------------------------------------------------------------------------------
void login::on_btnReinitialiser_clicked()
{
    static bool alreadyClicked = false;
    if (alreadyClicked) return;  // Évite un second appel
    alreadyClicked = true;

    QString email = ui->lineEditemailR->text().trimmed();
    QString nouveauPass = ui->nvPass->text().trimmed();
    QString confirmationPass = ui->confirmPass->text().trimmed();

    if (nouveauPass.isEmpty() || confirmationPass.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        alreadyClicked = false;  // Réinitialiser le flag en cas d'erreur
        return;
    }

    if (nouveauPass != confirmationPass) {
        QMessageBox::critical(this, "Erreur", "Les mots de passe ne correspondent pas.");
        ui->nvPass->clear();
        ui->confirmPass->clear();
        ui->nvPass->setFocus();
        alreadyClicked = false;
        return;
    }

    if (m_mainWindow && !m_mainWindow->verifierMotDePasse(nouveauPass, ui->labelErreur)) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un mot de passe valide.");
        ui->nvPass->clear();
        ui->confirmPass->clear();
        ui->labelErreur->clear();

        ui->nvPass->setFocus();
        alreadyClicked = false;
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(nouveauPass.toUtf8(), QCryptographicHash::Sha256);
    QString hashedPasswordStr = QString::fromUtf8(hashedPassword.toBase64());

    QSqlQuery query;
    query.prepare("UPDATE ZEINEB.ARCHITECTE SET MOT_DE_PASSE = :password WHERE EMAIL = :email");
    query.bindValue(":password", hashedPasswordStr);
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Succès", "Mot de passe réinitialisé avec succès!");
           // emit loginSuccess();
            QSqlQuery roleQuery;
            roleQuery.prepare("SELECT RÔLE FROM ARCHITECTE WHERE EMAIL = :email");
            roleQuery.bindValue(":email", email);

            if (roleQuery.exec() && roleQuery.next()) {
                QString userRole = roleQuery.value(0).toString();
                emit loginSuccess(userRole); // Déclenche l'accès au dashboard
            }}
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour: " + query.lastError().text());
    }

    alreadyClicked = false; // Réinitialiser après l'exécution complète
}


void login::on_btnConnecter_clicked()
{
    QString email = ui->lineEditEmail->text().trimmed();
    QString password = ui->lineEditPassword->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs");
        return;
    }

    if (authenticate(email, password)) {


           // emit loginSuccess();
            emit loginSuccess(m_role);

    } else {
        QMessageBox::critical(this, "Erreur", "Email ou mot de passe incorrect. Veuillez vérifier vos identifiants.");
        ui->lineEditPassword->clear();
        ui->lineEditEmail->setFocus();
    }
}

bool login::authenticate(const QString &email, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT MOT_DE_PASSE, RÔLE FROM ARCHITECTE WHERE EMAIL = :email");
    query.bindValue(":email", email.trimmed().toLower());

    if (!query.exec() || !query.next()) return false;

    QString storedPassword = query.value(0).toString();
    m_role = query.value(1).toString(); // Stocker le rôle

    QString inputPassword = QString::fromUtf8(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toBase64());

    return (inputPassword == storedPassword);
}

void login::on_btnMotDePasse_clicked()
{
    ui->loginWidget->setVisible(false);
    ui->mot_de_passe_oublie->setVisible(true);
    ui->mot_de_passe_oublie->setGeometry(ui->loginWidget->geometry());
    ui->btnRetour->setVisible(true); // Afficher le bouton
    ui->btnRetour->move(590, 420);
    // Réinitialisation des champs
    ui->lineEditemailR->clear();
    ui->question->clear();
    ui->lineEditemailR->setFocus();  // Donner le focus au champ email
}



void login::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
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

void login::on_btnRetour_clicked()
{
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetQuestion->setVisible(false);
    ui->widgetRei->setVisible(false);

    ui->loginWidget->setVisible(true);
    ui->btnRetour->setVisible(false); // Cacher le bouton

    // ... reste du code existant ...
}

// login.cpp
void login::clearInterface()
{ui->btnRetour->setVisible(false);
    // Réinitialisation des widgets
    ui->loginWidget->setVisible(true);
    ui->mot_de_passe_oublie->setVisible(false);
    ui->widgetQuestion->setVisible(false);
    ui->widgetRei->setVisible(false);

    // Vider les champs
    ui->lineEditEmail->clear();
    ui->lineEditPassword->clear();
    ui->lineEditemailR->clear();
    ui->lineEditReponse->clear();
    ui->nvPass->clear();
    ui->confirmPass->clear();

    // Réinitialiser les messages d'erreur
    ui->labelErreur->clear();
    ui->question->clear();
}

