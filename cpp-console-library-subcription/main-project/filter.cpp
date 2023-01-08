#include "filter.h"
#include <cstring>
#include <iostream>

wind** filter(wind* array[], int size, bool (*check)(wind* element), int& result_size)
{
	wind** result = new wind * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_book_subscription_by_author(wind* element)
{
	int n1 = strcmp(element->side_world.direction, "West");
	int n2 = strcmp(element->side_world.direction, "NorthWest");
	int n3 = strcmp(element->side_world.direction, "North");
	return n1 == 0 || n2 == 0 || n3 == 0;
}

bool check_book_subscription_by_date(wind* element)
{
	return element->meters.speed > 5;
}

