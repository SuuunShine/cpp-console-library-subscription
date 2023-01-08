#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "direction.h"

wind** filter(wind* array[], int size, bool (*check)(wind* element), int& result_size);



bool check_book_subscription_by_author(wind* element);




bool check_book_subscription_by_date(wind* element);



#endif

