#include "mysqlconn.h"
int main()
{
	mysqlconn sqlconn("tcp://127.0.0.1:3306","root","root");
	Connection *conn;
	conn=sqlconn.GetConnection();
	Statement *state;
	ResultSet *result;
	state=conn->createStatement();
	state->execute("use test");
	result=state->executeQuery("select * from user");
	while(result->next())
	{
		cout<<"id:\t"<<result->getInt("id")<<"\n";
		cout<<"name:\t"<<result->getString("name")<<endl;
		cout<<"age:\t"<<result->getInt("age")<<endl;
		cout<<"hometown:\t"<<result->getString("hometown")<<endl;
	}
	delete result;
	delete state;
	system("pause");
	return 0;
}