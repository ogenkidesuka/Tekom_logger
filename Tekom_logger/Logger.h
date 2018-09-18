/*�������� �������:

����������� ������.  ������ ����������  ������ �� ���������� �����. ��� ���������� ������������� �������,  
���������� ������������ � ����. ������ � ������� ������ ���� ������������ ����������:
	-�������� ����������� ��������� ����� ������������ ������;
	-������ ������� ����� ����� ��������, ��� ��� ����������  ������ ���� ������ ����� ����, � ������
	 ������������ ��� � ����;
	-��� ���������� ����������� ���������� ������  ������������ ������, �������� ������ ����� ���������.

����������� ������ ������������� �������.*/

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
	~Logger()	// - ��� ����������� ������� ��� ������ �������
	{
		std::ofstream fout;
		std::string fname = "Vol";
		if (GetDataSize() >= maxData)		// - ���� ��� �������� �����, �� ���������� ��������� ����� �����
			filecount = 0;
		filecount++;
		fname = fname + std::to_string(filecount) + ".txt";		// - std::to_string -- C++11
		fout.open(fname);
		for (int i = 0; i < buffer.size(); i++)
			fout << buffer.at(i);
		fout.close();
	}
	uint GetDataSize() // - ��������� �� ����� � ���� ������ �����, ����� ���������� ������, �� �-� ���. ������ ������ ������ �� �-�� ������� � �������� ���-�� ������
	{
		return (filecount + 1) * maxBuf;
	}
	uint GetBufferSize()
	{
		return buffer.size();
	}
	void Write(std::string msg)
	{
		/*������ Write ������ msg ����� ���������� � ��� \n => ������ write ������� msg.size()+1 ����*/

		if (msg.size() + buffer.size() >= maxBuf)	// - ���� ��������� �� ������� � ������
		{
			std::ofstream fout;
			std::string fname = "Vol";
			if (GetDataSize() >= maxData)		// - ���� ��� �� �������� �����, �� �������������� �� ����� � 1 (CurrentDataSize ����������!!!)
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
			buffer.push_back(msg.at(i));		// - ����� ����� � ���
		buffer.push_back('\n');
	}

};