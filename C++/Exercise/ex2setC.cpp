/*
Write the definition for a class called ‘time’ that has hours, minutes & seconds as integer data members. 
The class has the following member functions:
1.void settime(int, int, int) to set the specified values of hours, minutes and seconds in object
2.void showtime() to display contents of time object.
3. time add(time) add the corresponding values of hours, minutes and seconds (<60) in time object argument to current time object and make appropriate conversions and return time.
Write a main program to illustrate the use of above class.
*/

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    void settime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void showtime() {
        cout << "Time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    }

    Time add(Time t) {
        Time result;
        result.seconds = (seconds + t.seconds) % 60;
        result.minutes = (minutes + t.minutes + (seconds + t.seconds) / 60) % 60;
        result.hours = hours + t.hours + (minutes + t.minutes + (seconds + t.seconds) / 60) / 60;
        return result;
    }
};

int main() {
    Time time1, time2, result;

    // Accept input for the first time object
    int h1, m1, s1;
    cout << "Enter hours, minutes and seconds for Time 1: ";
    cin >> h1>> m1>> s1;
    // cout << "Enter minutes for Time 1: ";
    // cin >> m1;
    // cout << "Enter seconds for Time 1: ";
    // cin >> s1;
    time1.settime(h1, m1, s1);

    cout << "Time 1: ";
    time1.showtime();

    // Accept input for the second time object
    int h2, m2, s2;
    cout << "\nEnter hours, minutes and seconds for Time 2: ";
    cin >> h2>> m2>> s2;
    // cout << "Enter minutes for Time 2: ";
    // cin >> m2;
    // cout << "Enter seconds for Time 2: ";
    // cin >> s2;
    time2.settime(h2, m2, s2);

    cout << "Time 2: ";
    time2.showtime();

    // Add the two time objects
    result = time1.add(time2);

    // Display the result
    cout << "\nTotal Time: ";
    result.showtime();

    return 0;
}

