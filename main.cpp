//
//  main.cpp
//  Chapter4_TimeMachine_MPLProject
//
//  Created by on 3/6/22.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;

// Total number of minutes in an hour and day
const int MINUTES_IN_HOUR = 60;
const int MINUTES_IN_DAY = 24 * MINUTES_IN_HOUR;
char amPmChar1;
char amPmChar2;
char amPmChar3;
char amPmChar4;


// Function that computes the difference between two times
int compute_difference(int startHours, int startMinutes, int endHours, int endMinutes, bool startIsAM, bool endIsAM); // ***Add parameters list);

int main()
{
    int startHours;
    int startMinutes;
    bool startIsAM;
    int endHours;
    int endMinutes;
    int hours, minutes;
    int remainder;
    bool endIsAM;
    string print_minutes;
    string print_hours;
  
    char extra1; //IMPORTANT!!
    char extra2;
    char ans;

    do
    {
    
    cout << "Enter start time, in the format 'HH:MM xm' where 'xm' is either 'am' or 'pm' for AM or PM: ";
    cin >> startHours >> extra1 >> startMinutes >> amPmChar1 >> amPmChar3;
    if ((amPmChar1 == 'P') || (amPmChar1 == 'p'))
    {
        startIsAM = false;
    } else {
        startIsAM = true;
    }
    cout << "Enter future time, in the format 'HH:MM xm' where 'xm' is either 'am' or 'pm' for AM or PM: ";
    cin >> endHours >> extra2 >> endMinutes >> amPmChar2 >> amPmChar4;
    if ((amPmChar2 == 'P') || (amPmChar2 == 'p'))
    {
        endIsAM = false;
    } else {
        endIsAM = true;
    }

    
    minutes = compute_difference(startHours, startMinutes, endHours, endMinutes, startIsAM, endIsAM);
    hours = minutes / 60;
    remainder = minutes % 60;
    
    if ((hours > 1) || (hours == 0)){
        print_hours = " hours and ";
    } else {
        print_hours = " hour and ";
    }
    
    if ((remainder > 1) || (remainder == 0)){
        print_minutes = " minutes) between ";
    } else {
        print_minutes = " minute) between ";
    }

    if (remainder == 0) {
        cout << "There are " << minutes << " minutes " << "(" << hours << print_hours << remainder << print_minutes << startHours << extra1 << setfill('0') << setw(2) << startMinutes << " " << amPmChar1 << amPmChar3 << " and " << endHours << extra2 << setfill('0') << setw(2) << endMinutes << " " << amPmChar2 << amPmChar4 << "." << endl;
    } else {
        cout << "There are " << minutes << " minutes " << "(" << hours << print_hours << remainder << print_minutes << startHours << extra1 << setfill('0') << setw(2) << startMinutes << " " << amPmChar1 << amPmChar3 << " and " << endHours << extra2 << setfill('0') << setw(2) << endMinutes << " " << amPmChar2 << amPmChar4 << "." << endl;
    }
        cout << "Would you like to do travel again? (Y/N): ";
        cin >> ans;
    } while((ans == 'Y') || (ans == 'y'));
    
    cout << "Thanks for riding!" << endl;
    
    return 0;
}

int compute_difference(int startHours, int startMinutes, int endHours, int endMinutes, bool startIsAM, bool endIsAM)
{
    int diff, total_minutes1, total_minutes2;

    if (amPmChar1 != amPmChar2)
    {
        if (endIsAM == true)
        {
            if ((startHours >= 1) && (startHours <= 12))
            {
                startHours = startHours + 12;
            }
        }
        if (endIsAM == false)
        {
            if ((endHours >= 1) && (endHours <=12))
            {
                endHours = endHours + 12;
            }
        }

        total_minutes1 = (startHours * MINUTES_IN_HOUR) + startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
    }
    if ((amPmChar1 == amPmChar2) && ((startHours == 12) && (endHours == 12)))
    {
        startHours = startHours;
        endHours = endHours;
        total_minutes1 = startMinutes;
        total_minutes2 = endMinutes;

    } else if ((amPmChar1 == amPmChar2) && (startHours == 12)){
        startHours = startHours;
        endHours = endHours;
        total_minutes1 = startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
    } else if (startHours < 12) {
        startHours = startHours + 12;
        endHours = endHours + 12;
        total_minutes1 = (startHours * MINUTES_IN_HOUR) + startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
    }


    if (startHours >= endHours)
    {
        total_minutes2 = total_minutes2 + MINUTES_IN_DAY;
    }

    diff = total_minutes2 - total_minutes1;

    if (diff > MINUTES_IN_DAY)
    {
        diff = diff - MINUTES_IN_DAY;
    }

    return(diff);
}

