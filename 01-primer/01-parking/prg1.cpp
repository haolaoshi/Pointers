#include <iostream>
#include "d_time24.h"

using namespace std;

int main()
{
    const double PERHOUR_PARKING = 6.0; 
    time24 enterGarage, exitGarage,parkingTime;

    double billingHours;
    cout << "Enter the time s the car enters and exits the garage: "<<endl;
    enterGarage.readTime();
    exitGarage.readTime();

    parkingTime = enterGarage.duration(exitGarage);
    billingHours = parkingTime.getHour() + parkingTime.getMinute() / 60.0;
    cout << "Car enters at : " ;
    enterGarage.writeTime();
    cout << endl;

    cout << "Car exits at: ";
    exitGarage.writeTime();
    cout << endl;
    cout << "Parking time:";

    parkingTime.writeTime();
    cout <<endl;

    cout << "Cost is $"<<billingHours * PERHOUR_PARKING << endl;
    return 0;
}
