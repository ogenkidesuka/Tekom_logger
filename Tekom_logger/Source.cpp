#include "Logger.h"
#include <ctime>


int main()
{
	Logger test(20,200); // буффер -  10 сим, дата - 100 сим
	std::string message;
	for (int i = 0; i < 50; i++)
	{
		message = std::to_string(clock());
		test.Write(message);
	}
	std::string message1 = "dlinnaya stroka";
	std::string message2 = "fuk yea im done";
	std::string message3 = "yuyuyyu yu";
	test.Write(message1);
	test.Write(message2);
	test.Write(message3);
	return 0;
}