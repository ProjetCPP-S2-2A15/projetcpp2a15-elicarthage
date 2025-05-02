#ifndef EMAILNOTIFIER_H
#define EMAILNOTIFIER_H

#include <QString>

class EmailNotifier {
public:
    static void envoyerAlerte(const QString &objet, const QString &contenu);
};

#endif // EMAILNOTIFIER_H
