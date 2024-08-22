#include "db_user.h"

ClassThatUsesDB::ClassThatUsesDB(IDBConnection& connection) : connection_(connection) {}

bool ClassThatUsesDB::openConnection() {
    return connection_.open();
}

bool ClassThatUsesDB::closeConnection() { 
    return connection_.close(); 
}

bool ClassThatUsesDB::useConnection(const std::string& query) {
    return connection_.execQuery(query);
}