// Exercise 5.1
// This program illustrates the use of a while loop.
// The program is to calculate how many days it takes for
//     a person to make (in one day) $1,000,000, where
//     the person is paid $2 the 1st day,
//     $4 the 2nd day, $8 the 3rd day, $16 the 4th day, etc.
// Your program is to display the day and the pay for the day
//     and end the loop when the pay is $1,000,000 or over.

// Paul Badalian

#include <iostream>
using namespace std;

const double FIRST_PAY = 2.0;
const double MULTIPLIER = 2.0;
const double MAX_PAY = 1000000.00;

int main()
{
    double dailyPay;
    int day;

    // write the statement to initialize the day to 1
	
	day = 1;

    // write the statement to initialize the dailyPay to the FIRST_PAY

	dailyPay = FIRST_PAY;
	
    // fill in the condition for the while loop below so it ends
    //     when the dailyPay is at the MAX_PAY or more (opposite of while
    //     condition)
    while(dailyPay < MAX_PAY)
    {
        // display the day and daily pay with labels

		cout << "Day " << day << " pay " << dailyPay << endl;
		
        // increment the day
		
		day++;

        // calculate the next daily pay by multiplying it and saving back
        //     into dailyPay
		dailyPay *= MULTIPLIER;

    }

    cout << "Last day = " << day << " with pay = " << dailyPay << endl;

    return 0;
} // end main

/* Output 

Day 1 pay 2
Day 2 pay 4
Day 3 pay 8
Day 4 pay 16
Day 5 pay 32
Day 6 pay 64
Day 7 pay 128
Day 8 pay 256
Day 9 pay 512
Day 10 pay 1024
Day 11 pay 2048
Day 12 pay 4096
Day 13 pay 8192
Day 14 pay 16384
Day 15 pay 32768
Day 16 pay 65536
Day 17 pay 131072
Day 18 pay 262144
Day 19 pay 524288
Last day = 20 with pay 1.04858e+006

*/

