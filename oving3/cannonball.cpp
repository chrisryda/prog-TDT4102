#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "cannonball.h"
#include "utilities.h"

using namespace std;

double acclY() {
    return -9.81;
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY()* time;
}

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + (initVelocity * time);
}

double posY(double initPosition, double initVelocity, double time) {
    return initPosition + (initVelocity * time) + (acclY()*pow(time, 2)/2);
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity * cos(degToRad(theta));
}

double getVelocityY(double theta, double absVelocity) {
    return absVelocity * sin(degToRad(theta));
}

vector<double> getVelocityVector(double theta, double absVelocity) {
    return vector<double> {getVelocityX(theta, absVelocity), getVelocityY(theta, absVelocity)};
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return posX(0, velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

double getUserInputTheta() {
    double theta;
    cout << "Please enter valute of theta: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity() {
    double abs_velocity;
    cout << "Please enter absolute value of velocity: ";
    cin >> abs_velocity;
    return abs_velocity;
}

void printTime(double seconds) {
    int minutes = (int) floor(seconds / 60) % 60;
    int hours = (int) floor(seconds / 3600);
    cout << hours << " hours, " << minutes << " minutes and " << fixed << setprecision(2) << fmod(seconds, 60) << " seconds" << endl;
}

double flightTime(double initVelocityY) {
    return (-2*initVelocityY)/acclY();
}

double degToRad(double deg) {
    return (deg*M_PI)/180;
}

void playTargetPractice() {
    vector<double> velocity_vector;
    int target = randomWithLimits(100, 1000);
    double distance_traveled;

    for (int i = 0; i < 10; ++i) {
        double init_velocity = getUserInputAbsVelocity();
        double theta = getUserInputTheta();
        velocity_vector = getVelocityVector(theta, init_velocity);
        distance_traveled = getDistanceTraveled(velocity_vector[0], velocity_vector[1]);

        double deviation = target - distance_traveled;
        double abs_deviation = abs(target - distance_traveled);

        cout << "Distance to target: " << abs_deviation << " m" << endl;
        cout << "Flighg time of cannonball was ";
        printTime(flightTime(velocity_vector[1]));
        if (abs_deviation <= 5) {
            cout << "\n\n******************************" << endl;
            cout << "Congratulations, you have won!" << endl;
            return;
        }

        if (deviation > 0) {
            cout << "Your shot was too short!\n\n" << endl;
        } else {
            cout << "Your shot was too far!\n\n" << endl;
        }
    }
    cout << "\n\nI'm sorry, but you're out of luck - please try again!" << endl;
}
