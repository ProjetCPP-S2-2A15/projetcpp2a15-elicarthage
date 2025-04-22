#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QDate>
#include <QDebug>
#include <QLabel>


class Projet {
private:
    QString project_id;
    QString project_name;
    QString project_description;
    QDate project_date_deb;
    QString project_type;
    double project_budget;
    QString project_etat;
    QString lastError;

public:
    Projet() : project_budget(0.0) {}
    Projet(const QString &id, const QString &name, const QString &description,
           const QDate &date_deb, const QString &type, double budget, const QString &etat)
        : project_id(id), project_name(name), project_description(description),
        project_date_deb(date_deb), project_type(type), project_budget(budget), project_etat(etat) {}

    // Getters
    QString getProjectId() const { return project_id; }
    QString getProjectName() const { return project_name; }
    QString getProjectDescription() const { return project_description; }
    QDate getProjectDateDeb() const { return project_date_deb; }
    QString getProjectType() const { return project_type; }
    double getProjectBudget() const { return project_budget; }
    QString getProjectEtat() const { return project_etat; }
    QString getLastError() const { return lastError; }

    // Setters
    void setProjectId(const QString &id) { project_id = id; }
    void setProjectName(const QString &name) { project_name = name; }
    void setProjectDescription(const QString &description) { project_description = description; }
    void setProjectDateDeb(const QDate &date) { project_date_deb = date; }
    void setProjectType(const QString &type) { project_type = type; }
    void setProjectBudget(double budget) { project_budget = budget; }
    void setProjectEtat(const QString &etat) { project_etat = etat; }

    // CRUD
    bool addProjet();
    void display(QTableWidget *tableWidget);
    bool deleteProjet(const QString &projectId);
    bool updateProjet(const QString &originalId);
    //bool load(const QString &projectId);
};


#endif // PROJET_H
