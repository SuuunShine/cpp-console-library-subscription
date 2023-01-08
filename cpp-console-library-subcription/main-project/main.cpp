#include <iostream>
#include <iomanip>

using namespace std;

#include "direction.h"
#include "file_reader.h"
#include "constants.h"
#include "Header.h"
#include "filter.h"

void output(wind* subscription)
{
    /**********   **********/
    cout << "Direction: ";
    //  
    cout << setw(9) << setfill(' ') << subscription->side_world.direction << ".";
    //    



    /**********    **********/
    //  
    cout << " Date: ";

    //  
    cout << setw(2) << setfill('0') << subscription->start.month << '-';
    //  
    cout << setw(2) << setfill('0') << subscription->start.day;

    cout << " Speed: " << subscription->meters.speed << " m/s";
    cout << '\n';
    /**********    **********/
    //  
    //cout << " ...: ";

    //  

}


int main()
{

    setlocale(LC_ALL, "Russian");
    cout << "  9. GIT\n";
    cout << " 6.  \n";
    cout << ":  \n\n";
    cout << ": 11\n";
    wind* Wind[MAX_FILE_ROWS_COUNT];
    int size;

    try
    {
        read("data.txt", Wind, size);
        cout << "***** *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(Wind[i]);
        }
        bool  (*check_function)(wind*) = NULL;
        cout << "Choose filter:" << endl;
        cout << "1) By direction (West, NorthWest, North)" << endl;
        cout << "2) By speed (greater than 5 m/s)" << endl;
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_book_subscription_by_author; //       
            cout << "\n\n";
            break;
        case 2:
            check_function = check_book_subscription_by_date; //       
            cout << "\n\n";
            break;
        default:
            throw "Incorrect choise";
        }

        if (check_function)
        {
            int new_size;
            wind** result = filter(Wind, size, check_function, new_size);
            cout << "FILTEREED:" << endl << endl;
            for (int i = 0; i < new_size; i++)
            {
                output(result[i]);
            }
            delete[] result;
        }

        cout << "Choose sort: " << endl;
        cout << "1) Sort1" << endl;
        cout << "2) Sort2" << endl;
        cout << "3) Merge" << endl;
        int sort;
        cin >> sort;
        switch (sort)
        {
        case 1:
            Sort1(Wind, size);
            break;
        case 2:
            Sort2(Wind, size);
            break;
        case 3:
            MERG(Wind, size);
            break;
        }


        cout << endl << "SORTED ORIGINAL:" << endl << endl;
        for (int i = 0; i < size; i++)
        {
            output(Wind[i]);
        }


        for (int i = 0; i < size; i++)
        {
            delete Wind[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }


    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #9\n";
    cout << "Author: Levshicky Dmitry\n";
    cout << "Group: 11\n";

    return 0;
}


