//
// Created by Lukas Hajduch on 12/17/2023.
//
#include "Manager.h"
#include <sstream>
#include <fstream>

void Manager::addUser(User *user) {
    users.push_back((User *const) user);
}

std::vector<Ride*> Manager::findRides(const std::string &source, const std::string &destination) const{
    std::vector<Ride*> availableRides;
    for (unsigned int i = 0; i < users.size(); i++){
        User *oneUser = users[i];
        std::vector<Ride> rides = oneUser->getRides();
        for (Ride &oneRide : rides){
            if (source == oneRide.getStartingLocation() && destination == oneRide.getDestination()){
                if (oneRide.getAvailableSeatsForReservation() > 0){
                    Ride* rideCopy = new Ride(oneRide);
                    availableRides.push_back(rideCopy);
                }
            }
        }
    }
    return availableRides;
}
std::string Manager::showInfoAboutRides(const std::vector<Ride*>& rides){
    if (rides.empty()){
        return "No rides from this start location to that destination";
    }
    std::stringstream infoAboutRides;
    int counter = 1;
    for (const Ride *oneRide : rides){
        infoAboutRides << counter++ << ". ride: ";
        infoAboutRides << oneRide->showInfoAboutRide() << std::endl;
    }
    std::string infoAboutRidesString = infoAboutRides.str();
    return infoAboutRidesString.substr(0, infoAboutRidesString.size()-1);
}

bool Manager::reserveRide(User &user, Ride &ride){
    std::vector<Ride> ridesOfUser = user.getRides();
    for (const Ride& oneRide : ridesOfUser){
        if (oneRide.getRideIdentificationNumber() == ride.getRideIdentificationNumber()){
            return false;
        }
    }
    if (ride.getAvailableSeatsForReservation() > 0 && user.getReservedRide() == false && user.getMoney() > (ride.getRouteLength() * 0.01)){
        ride.setAvailableSeatsForReservation(ride.getAvailableSeatsForReservation()-1);
        ride.addIdOfPassengers(user.getUsername());
        user.setReservedRide(true);
        return true;
    }
    return false;
}

bool Manager::reserveVehicle(User &user, ElectricCar &vehicle, int distance) const{
    if (distance > vehicle.getBattery() || vehicle.getAvailability() == false || user.getMoney() < (distance * vehicle.getPricePerKilometer())) {
        return false;
    }
    vehicle.setBattery(vehicle.getBattery()-distance);
    if (vehicle.getBattery() < 10) {
        vehicle.setAvailability(false);
    }
    user.setMoney(user.getMoney() - distance * vehicle.getPricePerKilometer());
    return true;
}

bool Manager::reserveVehicle(User &user, ElectricBike &vehicle, int distance) const{
    if (distance > vehicle.getBattery() || vehicle.getAvailability() == false || user.getMoney() < (distance * vehicle.getPricePerKilometer())) {
        return false;
    }
    vehicle.setBattery(vehicle.getBattery()-distance);
    if (vehicle.getBattery() < 10) {
        vehicle.setAvailability(false);
    }
    user.setMoney(user.getMoney() - distance * vehicle.getPricePerKilometer());
    return true;
}

bool Manager::reserveVehicle(User &user, Scooter &vehicle, int distance) const {
    if (distance > vehicle.getBattery() || vehicle.getAvailability() == false || user.getMoney() < (distance * vehicle.getPricePerKilometer())) {
        return false;
    }
    vehicle.setBattery(vehicle.getBattery()-distance);
    if (vehicle.getBattery() < 10) {
        vehicle.setAvailability(false);
    }
    user.setMoney(user.getMoney() - distance * vehicle.getPricePerKilometer());
    return true;
}

void Manager::completePayment(User &user, Ride &ride) const{
    if (user.getReservedRide()){
        user.setMoney(user.getMoney() - (ride.getRouteLength() * (ride.getPricePer100Km() * 0.01)));
        user.setReservedRide(false);
    }
}

void Manager::addVehicle(Scooter *scooter1) {
    scooters.push_back(scooter1);
}

void Manager::addVehicle(ElectricCar *electricCar1) {
    electricCars.push_back(electricCar1);
}

void Manager::addVehicle(ElectricBike *electricBike1) {
    electricBikes.push_back(electricBike1);
}

std::string Manager::showAvailableAllVehicles() const{
    std::stringstream allVehicles;
    if (electricCars.size() > 0) {
        allVehicles << ELECTRIC_CARS_LABEL;
        for (ElectricCar *oneVehicle: electricCars) {
            if (oneVehicle->getAvailability()) {
                allVehicles << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
    }
    if (scooters.size() > 0) {
        allVehicles << SCOOTER_LABEL;
        for (Scooter *oneVehicle: scooters) {
            if (oneVehicle->getAvailability()) {
                allVehicles << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
    }
    if (electricBikes.size() > 0) {
        allVehicles << ELECTRIC_BIKE_LABEL;
        for (ElectricBike *oneVehicle: electricBikes) {
            if (oneVehicle->getAvailability()) {
                allVehicles << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
    }
    if (allVehicles.str().empty()) {
        return "No vehicles available";
    }
    std::string allVehiclesString = allVehicles.str();
    return allVehiclesString.substr(0,allVehiclesString.size()-1);
}

std::string Manager::showAvailableByType(const std::string &type) const{
    if (type == "Electric car") {
        std::stringstream vehiclesOfThisType;
        for (ElectricCar *oneVehicle: electricCars) {
            if (oneVehicle->getAvailability()) {
                vehiclesOfThisType << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
        if (vehiclesOfThisType.str().empty()) {
            return "No vehicles with this type";
        }
        std::string vehiclesOfThisTypeString = vehiclesOfThisType.str();
        return vehiclesOfThisTypeString.substr(0,vehiclesOfThisTypeString.size()-1);
    } else if (type == "Electric bike") {
        std::stringstream vehiclesOfThisType;
        for (ElectricBike *oneVehicle: electricBikes) {
            if (oneVehicle->getAvailability()) {
                vehiclesOfThisType << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
        if (vehiclesOfThisType.str().empty()) {
            return "No vehicles with this type";
        }
        std::string vehiclesOfThisTypeString = vehiclesOfThisType.str();
        return vehiclesOfThisTypeString.substr(0,vehiclesOfThisTypeString.size()-1);
    } else if (type == "Scooter") {
        std::stringstream vehiclesOfThisType;
        for (Scooter *oneVehicle: scooters) {
            if (oneVehicle->getAvailability()) {
                vehiclesOfThisType << oneVehicle->getIdentificationNumber() << std::endl;
            }
        }
        if (vehiclesOfThisType.str().empty()) {
            return "No vehicles with this type";
        }
        std::string vehiclesOfThisTypeString = vehiclesOfThisType.str();
        return vehiclesOfThisTypeString.substr(0,vehiclesOfThisTypeString.size()-1);
    }
    return "This type is not available";
}

bool Manager::deleteByType(const std::string &type) {
    if (type == "Electric car") {
        electricCars.clear();
        return true;
    } else if (type == "Electric bike") {
        electricBikes.clear();
        return true;
    } else if (type == "Scooter") {
        scooters.clear();
        return true;
    }
    return false;
}

void Manager::deleteAllVehicles() {
    electricCars.clear();
    electricBikes.clear();
    scooters.clear();
}

bool Manager::deleteByIdentificationNumber(const std::string &identificationNumber) {
    int counter = 0;
    for (auto it = electricCars.begin(); it != electricCars.end();) {
        if (electricCars.at(counter)->getIdentificationNumber() == identificationNumber) {
            electricCars.erase(it);
            return true;
        } else {
            ++it;
        }
        counter++;
    }
    counter = 0;
    for (auto it = scooters.begin(); it != scooters.end();) {
        if (scooters.at(counter)->getIdentificationNumber() == identificationNumber) {
            scooters.erase(it);
            return true;
        } else {
            ++it;
        }
        counter++;
    }
    counter = 0;
    for (auto it = electricBikes.begin(); it != electricBikes.end();) {
        if (electricBikes.at(counter)->getIdentificationNumber() == identificationNumber) {
            electricBikes.erase(it);
            return true;
        } else {
            ++it;
        }
        counter++;
    }
    return false;
}

void Manager::saveRideInfoIntoFile(User& user, Ride& ride){
    std::fstream file(user.getUsername()+ride.getRideIdentificationNumber()+".txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    file << ride.showInfoAboutRide();
    file.close();
}
std::string Manager::readRideInfoFromFile(const std::string &nameOfFile) {
    std::ifstream file;
    file.open(nameOfFile);
    if (!file){
        return "File cannot be opened.";
    }
    std::string oneRow;
    std::string subString;
    while (getline(file, oneRow, '\n')){
        size_t pos = oneRow.find(':');
        subString += oneRow.substr(pos+2, oneRow.size()) + ":";
    }
    return subString.substr(0,subString.size()-1);
}