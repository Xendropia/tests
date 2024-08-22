#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <string>

class IDBConnection {
public:
    virtual ~IDBConnection() {}
    virtual bool open() = 0;
    virtual bool close() = 0;
    virtual bool execQuery(const std::string& query) = 0;
};

#endif // DB_CONNECTION_H