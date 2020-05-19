// |--------------------|		   |-----------|
// | Subject            |	|-----|	Boss	   |
// |		 |---------|  	|	|	   |-----------|
// |	list| Observer|<-----------|	client	|
// |		 | Update()|   |	|	   |-----------|
// |		 |---------|   |	|-----|	Archiver |
// |					      |		   |-----------|
// | RegisterObserver()	|
// | NotifyObserver()	|
// |--------------------|

#include <string>
using std::string;
#include "Observer.h"
#include "Subject.h"

int main()
{
	Database database;

	Archiver archiver;
	Client client;
	Boss boss;

	database.RegisterObserver(&archiver);
	database.RegisterObserver(&client);
	database.RegisterObserver(&boss);

	database.EditRecord("delete","record 1");

	database.UnregisterObserver(&client);

	database.EditRecord("update","record 2");
}