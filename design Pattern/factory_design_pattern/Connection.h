#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class Connection
{
public:
	Connection()
	{}

	virtual	string Description()
	{
		return "Generic";
	}
};

class OracleConnection
	: public Connection
{
public:
	OracleConnection()
	{}

	string Description()
	{
		return "Oracle";
	}
};

class SQLServerConnection
	: public Connection
{
public:
	SQLServerConnection()
	{}

	string Description()
	{
		return "SQLServer";
	}
};

class MySQLConnection
	: public Connection
{
public:
	MySQLConnection()
	{}

	string Description()
	{
		return "MySQL";
	}
};
