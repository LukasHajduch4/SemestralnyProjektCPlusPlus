//
// Created by Lukas Hajduch on 12/15/2023.
//
#include "Vehicle.h"
#include <sstream>
#include <iostream>
bool Vehicle::getAvailability() const {
    return available;
}

bool Vehicle::addPricePerKilometer(const std::string& price) {
    // format of price: <pricePerKilometer>
    for (char oneChar : price){
        if ((oneChar == ' ') || (oneChar == '.') || ('0' <= oneChar && oneChar <= '9')){
            continue;
        }
        return false;
    }
    pricePerKilometer = std::stof(price);
    return true;
}

// Implementácia metód pre Kolobežku
std::string Scooter::showInfo() const {
    std::stringstream infoAboutScooter;
    infoAboutScooter << IDENTIFICATION_LABEL << identificationNumber << std::endl;
    infoAboutScooter << TYPE_OF_VEHICLE_LABEL << typesOfVehicles[typeOfVehicle] << std::endl;
    infoAboutScooter << BATTERY_LABEL << battery << "%" << std::endl;
    infoAboutScooter << PRICE_PER_KILOMETER_LABEL << pricePerKilometer;
    return infoAboutScooter.str();
}

// Implementácia metód pre Elektrické auto
std::string ElectricCar::showInfo() const {
    std::stringstream infoAboutElectricCar;
    infoAboutElectricCar << IDENTIFICATION_LABEL << identificationNumber << std::endl;
    infoAboutElectricCar << TYPE_OF_VEHICLE_LABEL << typesOfVehicles[typeOfVehicle] << std::endl;
    infoAboutElectricCar << BATTERY_LABEL << battery << "%" << std::endl;
    infoAboutElectricCar << PRICE_PER_KILOMETER_LABEL << pricePerKilometer << std::endl;
    infoAboutElectricCar << REGISTRATION_NUMBER_LABEL << spz << std::endl;
    if (airConditioning) {
        infoAboutElectricCar << AIR_CONDITIONING_LABEL << "YES" << std::endl;
    } else{
        infoAboutElectricCar << AIR_CONDITIONING_LABEL << "NO" << std::endl;
    }
    infoAboutElectricCar << NUMBER_OF_SEATS_LABEL << numberOfSeats << std::endl;
    infoAboutElectricCar << MODEL_OF_CAR_LABEL << model << std::endl;
    infoAboutElectricCar << ACCELERATION_LABEL << acceleration << " s" << std::endl;
    infoAboutElectricCar << MAXIMUM_RANGE_LABEL << maximumRange << " km" << std::endl;
    infoAboutElectricCar << TOP_SPEED_LABEL << topSpeed << " km/h";
    return infoAboutElectricCar.str();
}

// Implementácia metód pre Elektrický bicykel
std::string ElectricBike::showInfo() const {
    std::stringstream infoAboutElectricBike;
    infoAboutElectricBike << TYPE_OF_BIKE_LABEL << typesOfBikes[typeOfBike] << std::endl;
    infoAboutElectricBike << IDENTIFICATION_LABEL << identificationNumber << std::endl;
    infoAboutElectricBike << TYPE_OF_VEHICLE_LABEL << typesOfVehicles[typeOfVehicle] << std::endl;
    infoAboutElectricBike << BATTERY_LABEL << battery << "%" << std::endl;
    infoAboutElectricBike << PRICE_PER_KILOMETER_LABEL << pricePerKilometer;
    return infoAboutElectricBike.str();
}
