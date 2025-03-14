#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>

class Connection {
public:
    Connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
