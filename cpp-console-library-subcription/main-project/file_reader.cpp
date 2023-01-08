##include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
	date result;
	char* context = NULL;
	char* str_number = strtok_s(str, ".", &context);
	result.day = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.month = atoi(str_number);
	return result;
}
Speed conver(char* str)

{
	Speed result;
	char* context = NULL;
	char* str_number = strtok_s(str, ".", &context);
	result.speed = atoi(str_number);
	return result;
}

void read(const char* file_name, wind* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			wind* item = new wind;
			file >> tmp_buffer;
			item->start = convert(tmp_buffer);


			//file >> tmp_buffer;
			file >> item->side_world.direction;
			file >> item->meters.speed;
			//file.read(tmp_buffer, 1);


			array[size++] = item;

		}
		file.close();
	}
	else
	{
		throw "  ";
	}
}

