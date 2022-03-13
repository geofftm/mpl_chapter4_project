//
//  main.cpp
//  Chapter4_TimeMachine_MPLProject
//
//  Created by on 3/6/22.
//

//Directives for the libraries contained in the respective header files.

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

// Declaring the namespace
using namespace std;

// Declaring and initializing Global Constants for total minutes in an hour and minutes in a day
const int MINUTES_IN_HOUR = 60;
const int MINUTES_IN_DAY = 24 * MINUTES_IN_HOUR;

// Declaring global variables for the different characters that will be inputted by the user to represent time

char amPmChar1;
char amPmChar2;
char amPmChar3;
char amPmChar4;


// Declaring the function that computes the difference between two different times of day. The function takes 6 parameters/arguments and returns an int value. The six parameters are the start hours (int), the start minutes (int), the end hours (int), the end minutes (int), a bool representing whether the starting hour is in the morning or evening, a bool representing whether the ending hour is in the morning or evening

int compute_difference(int startHours, int startMinutes, int endHours, int endMinutes, bool startIsAM, bool endIsAM);

int main()
{
    //declaring varialbes (scope is main function)
    int startHours;
    int startMinutes;
    bool startIsAM;
    int endHours;
    int endMinutes;
    int hours, minutes;
    int remainder;
    bool endIsAM;
    
    // To account for the different grammatical issues that might come up with different permutations of hours/minutes I decided to make some string variables that will be initialized and printed based on the hours and minutes.
    string print_minutes;
    string print_hours;
    
    // Declaring char variables (extra1 and extra2) to hold the pieces of the time inputted by the user as well as well 'ans' which will store the character for the do-while loop.
  
    char extra1;
    char extra2;
    char ans;
    
    // A do-while loop that will continue to ask for input from the user so that the program doesn't have to be manually run if you want to calculate more than one time consectuively.

    do
    {
    // User prompt for times/format - the hour(s) to the left of the ":" is stored in startHours, the ":" itself is stored in extra1, the minutes to the right of the ":" are stored in startMinutes, the character representing morning or evening ('a' or 'p') is stored in amPmChar1 and amPmChar3 stores the second character ('m') in 'am' or 'pm'
    cout << "Enter start time, in the format 'HH:MM xm' where 'xm' is either 'am' or 'pm' for AM or PM: ";
    cin >> startHours >> extra1 >> startMinutes >> amPmChar1 >> amPmChar3;
    // Here there is an if statement that initialize a bool variable depending on the time of day
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

    // The function compute_difference() is called and the value, an integer which is the difference between the start and ending times in minutes, is stored in the variable minutes.
    minutes = compute_difference(startHours, startMinutes, endHours, endMinutes, startIsAM, endIsAM);
    // Here the number of hours is calculated and that value is used to initialize the 'hours' variable
    hours = minutes / MINUTES_IN_HOUR;
    // Here the remainder (representing the minutes left over from the hours calculation) is calculated and that value is used to intialize the 'remainder' variable which will reprsent the number of minutes in an hour.
    remainder = minutes % MINUTES_IN_HOUR;
    // Setting some of the strings in the print statement so the user sees a gramatically correct sentence explaining the number of hours and minutes. For example, if the hours total greater than 1 or are equal to 0, this statement will initialize the string variable print_hours so that the print statement will read '2 hours' or '0 hours' instead of '2 hour' or '0 hour'.
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
    // If-Else statement that determines what is printed based on the remainder in minutes. Again this is just so the print statement reads well and makes sense to the user.
    if (remainder == 0) {
        cout << "There are " << minutes << " minutes " << "(" << hours << print_hours << remainder << print_minutes << startHours << extra1 << setfill('0') << setw(2) << startMinutes << " " << amPmChar1 << amPmChar3 << " and " << endHours << extra2 << setfill('0') << setw(2) << endMinutes << " " << amPmChar2 << amPmChar4 << "." << endl;
    } else {
        cout << "There are " << minutes << " minutes " << "(" << hours << print_hours << remainder << print_minutes << startHours << extra1 << setfill('0') << setw(2) << startMinutes << " " << amPmChar1 << amPmChar3 << " and " << endHours << extra2 << setfill('0') << setw(2) << endMinutes << " " << amPmChar2 << amPmChar4 << "." << endl;
    }
        // This statement is printed asking the user if they'd like to perform another calculation. If the answer is 'Y' then the program runs all over again. If the answer is anything else, the program ends.
        cout << "Would you like to time travel again? (Y/N): ";
        cin >> ans;
    } while((ans == 'Y') || (ans == 'y'));
    
    // When the user terminates the program, this message is displayed to let them know it's closing
    
    cout << "Thanks for riding along! Good bye!" << endl;
    
    return 0;
}

// Definition for the function computer_difference() - Function Header
int compute_difference(int startHours, int startMinutes, int endHours, int endMinutes, bool startIsAM, bool endIsAM)
{
    // Function body begins
    // Declaring local variables to be used in the scope of the function (declared in the function body
    int diff, total_minutes1, total_minutes2;
    
    // If-Else statement used to determine how to begin calcuating the hours. Here the program is checking to see if the amPmChar variables are different. If they are (meaning one is AM and one is PM), then this part of the program will make the calculations across an entire day (as opposed to just a morning or an evening)
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
            if ((endHours >= 12) && (endHours < 24))
            {
                endHours = endHours + 12;
            }
        }
        // Total Minutes are calculated and that value initializes the two total_minutes variables (each representing the starting and ending hours and minutes respectively.
        total_minutes1 = (startHours * MINUTES_IN_HOUR) + startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
    }
        // Total Minutes are calcuated based on when the amPmChars are the same and when both starting and ending hours are '12'.
    if ((amPmChar1 == amPmChar2) && ((startHours == 12) && (endHours == 12)))
    {
        startHours = startHours;
        endHours = endHours;
        total_minutes1 = startMinutes;
        total_minutes2 = endMinutes;
        // Total Minutes are calcuated based on when the amPmChars are the same and when just the starting and hour is '12'
    } else if ((amPmChar1 == amPmChar2) && (startHours == 12)){
        startHours = startHours;
        endHours = endHours;
        total_minutes1 = startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
        // Start and end hours are set based on when the starting hours are less than 12. These values are used to calculate the total minutes.
    } else if (startHours <= 12) {
        startHours = startHours + 12;
        endHours = endHours + 12;
        total_minutes1 = (startHours * MINUTES_IN_HOUR) + startMinutes;
        total_minutes2 = (endHours * MINUTES_IN_HOUR) + endMinutes;
    }

    // Here if start hours are greater than or equal to end hours, the original value of total_minutes2 is incremented with the original value plus the the total minutes in a day
    if (startHours >= endHours)
    {
        total_minutes2 = total_minutes2 + MINUTES_IN_DAY;
    }
    // Here the difference between the end hours and starting hours are calculated and that value is used to initialize the diff value
    diff = total_minutes2 - total_minutes1;
    // If the value of diff exceeds the total in minutes in a day, than this if statement subtracts the total minutes of the day, to ensure that the calculation is correct.
    if (diff > MINUTES_IN_DAY)
    {
        diff = diff - MINUTES_IN_DAY;
    }
    
    // Return statement for the difference between times.
    return(diff);
}

