// |--------------------|
// |	Factory			|		|-----------|			|-------------------|
// |		Create()	|<----->|Connection	| <-------- |OracleConnection	|
// |					|		|-----------|	|		|-------------------|
// |--------------------|						|------	|MySQLConnection	|
//												|		|-------------------|
//												|------	|SQLserverConnection|
//														|-------------------|

#include "Connection.h" // 1.
#include "FirstFactory.h"// 2.
#include "ConnectionFactory.h"// 3.

int main()
{
	// simpleFactory
	FirstFactory factory("MySQL");

	Connection * connect= factory.CreateConnection();

	cout << connect->Description() << endl;

	// Abstract Factory
	SecureConnection secureConnect;

	if (connect) delete connect;
	connect = secureConnect.CreateConnection("Oracle");

	cout << connect->Description() << endl;
}