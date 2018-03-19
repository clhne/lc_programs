#include <iostream>
#include <math.h>
using namespace std;
float roll,pitch,yaw;
float q1 = 1.0;
float q2 = 2.0;
float q3 = 3.0;
float q4 = 4.0;
	
float invSqrt(float x)
{
	float halfx = 0.5f * x;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i>>1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	y = y * (1.5f - (halfx * y * y));
	return y;
}
void computeAngles()
{
	roll = atan2f(q1*q2 + q3*q4, 0.5f - q2*q2 - q3*q3);
	pitch = asinf(-2.0f * (q2*q4 - q1*q3));
	yaw = atan2f(q2*q3 + q1*q4, 0.5f - q3*q3 - q4*q4);
}
float getRoll() {
	computeAngles();
	return roll * 57.29578f;
}
float getPitch() {
	computeAngles();
	return pitch * 57.29578f;
}
float getYaw() {
	computeAngles();
	return yaw * 57.29578f + 180.0f;
}
int main(){

    float recipNorm = invSqrt(q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);
	q1 *= recipNorm;
	q2 *= recipNorm;
	q3 *= recipNorm;
	q4 *= recipNorm;
    computeAngles();
    /*
    roll = getRoll();
    pitch = getPitch();
    yaw = getYaw();
    */
    cout<<"roll = "<<roll<<endl;
    cout<<"pitch = "<<pitch<<endl;
    cout<<"yaw = "<<yaw<<endl;
    return 0;
}