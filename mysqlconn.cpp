#include<stdexcept>
#include<exception>
#include<stdio.h>
#include "mysqlconn.h"

mysqlconn::mysqlconn(std::string url, std::string user, std::string password)
{
	this->url=url;
	this->username=user;
	this->password=password;
	try{
		this->driver=sql::mysql::get_driver_instance();
		
	}catch(sql::SQLException &e)
	{
		perror("driver connection error!\n");
	}catch(std::runtime_error &e)
	{
		perror("runtime error!\n");
	}
	this->CreateConnection();
}
void mysqlconn::CreateConnection()
{
	try{
		this->conn=driver->connect(this->url,this->username,this->password);
		cout<<"creating connection success"<<endl;
		return;
	}catch(sql::SQLException&e)
	{
		perror("creating connection error!");
		return;
	}catch(std::runtime_error &e){
		perror("runtime error!");
		return;
	}
}
mysqlconn::~mysqlconn()
{
	this->destroy();
}
void mysqlconn::destroy()
{
	if(this->conn)
	{
		try{
			this->conn->close();
		}catch(sql::SQLException&e)
		{
			perror(e.what());
		}catch(std::exception&e)
		{
			perror(e.what());
		}
		delete conn;
	}
}
Connection* mysqlconn::GetConnection()
{
	if(this->conn!=NULL)
	{
		return this->conn;
	}
	else
	{
		this->CreateConnection();
		if(this->conn)
		{
			return this->conn;
		}
	}
}