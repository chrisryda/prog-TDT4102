#pragma once
#include <vector>

double acclY();
double velY(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
std::vector<double> getVelocityVector(double theta, double absVelocity);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

double getUserInputTheta();
double getUserInputAbsVelocity();

void printTime(double seconds);
double flightTime(double initVelocityY);
double degToRad(double deg);

void playTargetPractice();
