class FirstFactory
{
	string type_;
public:
	FirstFactory(string type)
		:type_(type)
	{}

	Connection * CreateConnection()
	{
		if (type_ == "Oracle")
		{
			return new OracleConnection();
		} 
		else if (type_ == "SQLServer")
		{
			return new SQLServerConnection();
		} 
		else 
		{
			return new MySQLConnection();
		}
	}
};