#include "database.h"
#include "db_config.h"
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/exception.h>
#include <iostream>

std::shared_ptr<sql::Connection> conn;

void connectToDB() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        conn = std::shared_ptr<sql::Connection>(
            driver->connect(DB_HOST, DB_USER, DB_PASSWORD)
        );
        conn->setSchema(DB_NAME);
        std::cout << "Database connected successfully.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "Connection error: " << e.what() << std::endl;
    }
}

void closeDB() {
    if (conn) {
        conn->close();
        std::cout << "Database connection closed.\n";
    }
}
