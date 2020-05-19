class ConnectionFactory
{
public:
	ConnectionFactory()
	{}

	virtual Connection * CreateConnection(string t)=0;
};

class SecureConnection
	:public ConnectionFactory
{
public:
	SecureConnection()
	{}

	Connection * CreateConnection(string type)
	{
		if (type == "Oracle")
		{
			return new OracleConnection();
		} 
		else if (type == "SQLServer")
		{
			return new SQLServerConnection();
		} 
		else 
		{
			return new MySQLConnection();
		}
	}
};