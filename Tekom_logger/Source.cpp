#include "Logger.h"
#include <ctime>


int main(uint bs = 200, uint ds = 1000)
{
	Logger test(20,400); // буффер -  10 сим, дата - 100 сим
	std::string message;
	for (int i = 0; i < 20; i++)
	{
		message = std::to_string(clock());
		test.sdf(message);
		test.Write(message);
	}
	std::string message1 = "Bibaran";
	std::string message2 = "Ansha Abdul";
	std::string message3 = "Xyu po koleho";
	test.sdf(message1);
	test.Write(message1);
	test.sdf(message2);
	test.Write(message2);
	test.sdf(message3);
	test.Write(message3);
	return 0;
}