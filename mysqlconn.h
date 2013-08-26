#ifndef MYSQLCONN_H
#define MYSQLCONN_H
#include <mysql_connection.h>  
#include <mysql_driver.h>  
#include <statement.h> 
#include <prepared_statement.h>
#include <exception.h>
#include <driver.h>
#include <connection.h>
#include <resultset.h>
using namespace sql;
using namespace std;
class mysqlconn
{	
private:
	string username;
	string password;
	string url;
	Driver* driver;
	Connection *conn;
	void CreateConnection();
	void destroy();
public:
	mysqlconn(string url,string user,string password);
	~mysqlconn();
	Connection* GetConnection();
	
};
#endif