#pragma once
#ifndef DIRECTION_H
#define DIRECTION_H
#include "constants.h"

struct date
{
	int day;
	int month;
};

struct direction
{
	char direction[MAX_STRING_SIZE];
};
struct Speed
{
	double speed;
};
struct wind
{
	date start;

	direction side_world;
	Speed meters;

};
#endif

