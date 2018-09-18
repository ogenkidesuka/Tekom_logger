/*Тестовое задание:

Реализовать логгер.  Логгер записывает  данные во внутренний буфер. При достижении определенного размера,  
информация записывается в файл. Работа с файлами должна быть организована циклически:
	-задается максимально возможный объем записываемых данных;
	-размер каждого файла также известен, при его достижении  должен быть создан новый файл, и запись
	 производится уже в него;
	-при достижении максимально возможного объема  записываемых данных, наиболее старые файлы удаляются.

Реализовать пример использования логгера.*/

#pragma once
//#pragma warning(disable:4996)

#include <fstream>
#include <string>
#include <vector>

typedef unsigned int uint;

class Logger
{
private:
	std::vector<char> buffer;
	uint maxBuf;
	uint maxData;
	uint filecount;

	
public:
	Logger(const uint& mb, const uint& md)
	{
		filecount = 0;
		maxBuf = mb;
		maxData = md;
	}
	~Logger()	// - при уничтожении логгера нид буффер вывести
	{
		std::ofstream fout;
		std::string fname = "Vol";
		if (GetDataSize() >= maxData)		// - если еще осталось место, то продолжаем создавать новые файлы
			filecount = 0;
		filecount++;
		fname = fname + std::to_string(filecount) + ".txt";		// - std::to_string -- C++11
		fout.open(fname);
		for (int i = 0; i < buffer.size(); i++)
			fout << buffer.at(i);
		fout.close();
	}
	uint GetDataSize() // - поскольку мы пишем в файл только тогда, когда заполнится буффер, то р-р инф. считаю только исходя из р-ра буффера и текущего кол-ва файлов
	{
		return (filecount + 1) * maxBuf;
	}
	uint GetBufferSize()
	{
		return buffer.size();
	}
	void Write(std::string msg)
	{
		/*Каждый Write помимо msg будет записывать в буф \n => каждый write добавит msg.size()+1 байт*/

		if (msg.size() + buffer.size() >= maxBuf)	// - если сообщение не влезает в буффер
		{
			std::ofstream fout;
			std::string fname = "Vol";
			if (GetDataSize() >= maxData)		// - если уже не осталось места, то перезаписываем по новой с 1 (CurrentDataSize поменяется!!!)
				filecount = 0;
			filecount++;
			fname = fname + std::to_string(filecount) + ".txt";		// - std::to_string -- C++11
			fout.open(fname);
			for (int i = 0; i < buffer.size(); i++)
				fout << buffer.at(i);
			fout.close();
			buffer.clear();
		}
		for (int i = 0; i < msg.size(); i++)
			buffer.push_back(msg.at(i));		// - пишем сообщ в буф
		buffer.push_back('\n');
	}

};