/******************************************************************************************************************************
This problem was asked by Microsoft.
Given a clock time in hh:mm format, determine, to the nearest degree, the angle between the hour and the minute hands.
Bonus: When, during the course of a day, will the angle be zero?
******************************************************************************************************************************/

#include <iostream>
using namespace std;

int getAngle(double hh, double mm){
    if(hh<0 && hh>12 || mm<0 && mm>60){
        cout<<"Please enter  correct input"<<endl;
        return -1;
    }
    hh = (hh==12)?0:hh;
    mm = (mm==60)?0:mm;
    int h_angle = 0.5*(hh*60+mm);
    int m_angle = 6*mm;
    int diff = abs(h_angle-m_angle);
    diff = min(diff,360-diff);
    return diff;
}

int main() {
    cout<<getAngle(12,10)<<endl;
	return 0;
}
