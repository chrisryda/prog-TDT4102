#include "Car.h"

Car::Car(int freeSeats) {
    this->freeSeats = freeSeats;
}

bool Car::hasFreeSeats() const {
    return (freeSeats > 0);
}

void Car::reserveFreeSeat() {
    freeSeats--;
}
