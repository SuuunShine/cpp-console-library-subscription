#include "Header.h"
#include <iostream>
#include <string.h>
#include "file_reader.h"
#include "constants.h"

using namespace std;

bool cmp(wind* a, wind* b) {
    int n = a->start.month - b->start.month;
    if (n < 0) {
        return true;
    }
    else if (n > 0) {
        return false;
    }
    else {
        n = a->start.day - b->start.day;
        return n < 0;
    }
}


void MERG(wind** array, int size)
{
    int mid = size / 2; //    
    if (size % 2 == 1)
        mid++;
    int h = 1; // 
    //     
    wind** c = new wind * [size];
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   //   
        int j = mid; //   
        int k = 0;   //     
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { //      
              //     
              //    
                if (strcmp(array[i]->side_world.direction, array[j]->side_world.direction) > 0)
                {
                    c[k] = array[i];
                    i++; k++;
                }
                else {
                    c[k] = array[j];
                    j++; k++;
                }
            }
            while (i < step)
            { //      (   )
                c[k] = array[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            {  //      (   )
                c[k] = array[j];
                j++; k++;
            }
            step = step + h; //    
        }
        h = h * 2;
        //    ( )   
    }
    for (int i = 0; i < size; i++)
        array[i] = c[i];
}
void Sort1(wind** array, int size)
{
    bool sort_or_not;
    do {
        sort_or_not = true;
        for (int i = 0; i < size - 1; i++) { // n -   
            if (array[i]->meters.speed < array[i + 1]->meters.speed) {
                swap(array[i], array[i + 1]);
                sort_or_not = false;
            }
        }
        for (int i = size - 1; i >= 1; i--) {
            if (array[i]->meters.speed > array[i - 1]->meters.speed) {
                swap(array[i]->meters.speed, array[i - 1]->meters.speed);
                sort_or_not = false;
            }
        }
    } while (!sort_or_not);
}
void Sort2(wind** array, int size)
{
    bool sort_or_not;
    do {
        sort_or_not = true;
        for (int i = 0; i < size - 1; i++) { // n -   
            if (cmp(array[i], array[i + 1])) {
                swap(array[i], array[i + 1]);
                sort_or_not = false;
            }
        }
        for (int i = size - 1; i >= 1; i--) {
            if (cmp(array[i - 1], array[i])) {
                swap(array[i]->start.month, array[i - 1]->start.month);
                sort_or_not = false;
            }
        }
    } while (!sort_or_not);
}

