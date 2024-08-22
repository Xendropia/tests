#ifndef DB_USER_H
#define DB_USER_H

#include "db_connection.h"

class ClassThatUsesDB {
public:
    ClassThatUsesDB(IDBConnection& connection);
    bool openConnection();
    bool closeConnection();
    bool useConnection(const std::string& query);

private:
    IDBConnection& connection_;
};

#endif // DB_USER_H