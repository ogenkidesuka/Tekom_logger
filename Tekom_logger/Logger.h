#pragma once
#pragma warning(disable:4996)

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

typedef unsigned int uint;

class Logger
{
private:
	std::vector<char> buffer;
	uint maxBuf;
	uint maxData;
	uint filecount;

	uint CurrentDataSize()
	{
		return (filecount+1) * maxBuf;
	}
public:
	void sdf(std::string msg)
	{
		std::cout << buffer.size() + msg.size() << "<" << maxBuf << "=>" << (buffer.size() + msg.size() < maxBuf) << std::endl;
	}
	Logger(const uint& mb, const uint& md)
	{
		filecount = 0;
		maxBuf = mb;
		maxData = md;
	}
	void Write(std::string msg)
	{
		if (msg.size() + buffer.size() < maxBuf)	// - если сообщение влезает в буффер
			for (int i = 0; i < msg.size(); i++)
				buffer.push_back(msg.at(i));		// - пишем сообщ в буф
		else										// - иначе
		{
			std::ofstream fout;
			std::string fname = "Vol";
			if (CurrentDataSize() >= maxData)		// - если еще осталось место, то продолжаем создавать новые файлы
				filecount = 0;
			filecount++;
			fname = fname + std::to_string(filecount) + ".txt";		// - std::to_string -- C++11
			fout.open(fname);
			for (int i = 0; i < buffer.size(); i++)
				fout << buffer.at(i);
			fout.close();

			buffer.clear();
		}
	}
};