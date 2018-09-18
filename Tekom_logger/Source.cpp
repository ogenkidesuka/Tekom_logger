#include "Logger.h"
#include <iostream>

using namespace std;

int main()
{
	/*Logger test(20,200); // буффер -  10 сим, дата - 100 сим
	std::string message;
	for (int i = 0; i < 50; i++)
	{
		message = std::to_string(i);
		test.Write(message);
	}
	std::string message1 = "dlinnaya stroka";
	std::string message2 = "fuk yea im done";
	std::string message3 = "yuyuyyu yu";
	test.Write(message1);
	test.Write(message2);
	test.Write(message3);*/
	uint bs, ds;									// - р-р буффера и данных соотв.
	cout << "Enter the size of buffer (bytes): ";
	cin >> bs;
	cout << "\nEnter the size of data (bytes): ";
	cin >> ds;
	Logger myLog(bs, ds);

	int sel;
	system("cls");
	do
	{
		system("cls");
		cout << "MyLogger(" << bs << ", " << ds << ")"
			<< "\n\nCurrent Buffer: " << myLog.GetBufferSize()
			<< "\nCurrent Data: " << myLog.GetDataSize()
			<< "\n\n1. Write custom string"
			<< "\n2. Write numbers 1 - 100"
			<< "\n0. Exit\n\n";
		cin >> sel;
		system("cls");

		switch (sel)
		{
		case 1:
		{
			string msg;
			cout << "Enter message: ";
			cin >> msg;
			myLog.Write(msg); break;
		}
		case 2:
		{
			for (int i = 1; i <= 100; i++)
				myLog.Write(to_string(i));
			break;
		}
		default:
			break;
		}
	} while (sel != 0);
	system("pause");
	return 0;
}