#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
#include <jdbc/cppconn/connection.h>

extern std::shared_ptr<sql::Connection> conn;

void connectToDB();
void closeDB();

#endif
