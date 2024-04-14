//
// Created by Lukas Hajduch on 12/17/2023.
//

#ifndef SEMESTRALNYPROJECT_MANAGER_H
#define SEMESTRALNYPROJECT_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Vehicle.h"
#include "Ride.h"

const std::string ELECTRIC_CARS_LABEL = "Electric cars: ";
const std::string SCOOTER_LABEL = "Scooters: ";
const std::string ELECTRIC_BIKE_LABEL = "Electric bikes: ";

class Manager {
private:
    std::vector<User*> users;
    std::vector<ElectricCar*> electricCars;
    std::vector<ElectricBike*> electricBikes;
    std::vector<Scooter*> scooters;

public:
    void addUser(User *user);
    std::vector<Ride*> findRides(const std::string& source, const std::string& destination) const;
    static std::string showInfoAboutRides(const std::vector<Ride*>& rides);
    static bool reserveRide(User& user, Ride& ride);
    bool reserveVehicle(User& user, ElectricCar& vehicle, int distance) const;
    bool reserveVehicle(User& user, ElectricBike& vehicle, int distance) const;
    bool reserveVehicle(User& user, Scooter& vehicle, int distance) const;
    void completePayment(User& user, Ride& ride) const;
    void addVehicle(Scooter* scooter1);
    void addVehicle(ElectricCar* electricCar1);
    void addVehicle(ElectricBike* electricBike1);
    std::string showAvailableAllVehicles() const;
    std::string showAvailableByType(const std::string& type) const;
    bool deleteByType(const std::string& type);
    void deleteAllVehicles();
    bool deleteByIdentificationNumber(const std::string& identificationNumber);
    void saveRideInfoIntoFile(User& user, Ride& ride);
    std::string readRideInfoFromFile(const std::string& nameOfFile);
};

#endif //SEMESTRALNYPROJECT_MANAGER_H
