//
// Created by Lukas Hajduch on 12/15/2023.
//

#ifndef SEMESTRALNYPROJECT_VEHICLE_H
#define SEMESTRALNYPROJECT_VEHICLE_H

#include <string>
#include <iomanip>
#include <sstream>

const std::string IDENTIFICATION_LABEL = "Identification Number: ";
const std::string TYPE_OF_VEHICLE_LABEL = "Type of vehicle: ";
const std::string BATTERY_LABEL = "Battery: ";
const std::string PRICE_PER_KILOMETER_LABEL = "Price per Kilometer: ";
const std::string REGISTRATION_NUMBER_LABEL = "Registration Number: ";
const std::string AIR_CONDITIONING_LABEL = "Air Conditioning: ";
const std::string NUMBER_OF_SEATS_LABEL = "Number of Seats: ";
const std::string MODEL_OF_CAR_LABEL = "Model of Car: ";
const std::string ACCELERATION_LABEL = "Acceleration (0-100): ";
const std::string MAXIMUM_RANGE_LABEL = "Maximum Range: ";
const std::string TOP_SPEED_LABEL = "Top Speed: ";
const std::string TYPE_OF_BIKE_LABEL = "Type of bike: ";
enum TypesOfVehicles { SCOOTER, ELECTRIC_CAR, ELECTRIC_BIKE };
const std::string typesOfVehicles[] = {"Scooter", "Electric car", "Electric bike"};

enum TypesOfBikes { TANDEM, CARGO, CLASSIC, KIDS };
const std::string typesOfBikes[] = {"Tandem", "Cargo", "Classic", "Kids"};
class Vehicle {
protected:
    std::string identificationNumber;
    TypesOfVehicles typeOfVehicle;
    float pricePerKilometer{};
    bool available = true;
    int battery{};

public:
    virtual ~Vehicle() = default;
    bool getAvailability() const;
    bool addPricePerKilometer(const std::string& price);
    const std::string& getTypeofVehicle() const {
        return typesOfVehicles[typeOfVehicle];
    }
    float getPricePerKilometer() const {
        return pricePerKilometer;
    }
    const std::string& getIdentificationNumber() const {
        return identificationNumber;
    }
    int getBattery() const {
        return battery;
    }
    void setBattery(int newBatteryLevel){
        if (available == false && newBatteryLevel > 10) {
            available = true;
        }
        battery = newBatteryLevel;
    }
    void setAvailability(bool isAvailable){
        available = isAvailable;
    }
};

class Scooter : public Vehicle {
public:
    Scooter() {
        typeOfVehicle = TypesOfVehicles::SCOOTER;
        battery = 100; // Predpokladaná plná kapacita batérie
        static int scooterCount = 1;
        std::stringstream numberOfScooter;
        numberOfScooter << std::setw(3) << std::setfill('0') << std::to_string(scooterCount++);
        identificationNumber = "KK" + numberOfScooter.str();
    }

    std::string showInfo() const;
};

class ElectricCar : public Vehicle {
private:
    bool airConditioning;
    int numberOfSeats;
    std::string model;
    int acceleration;
    int maximumRange;
    int topSpeed;
    std::string spz;
public:
    ElectricCar(const std::string& spz1, const std::string& model1, const int numberOfSeats1, const bool airConditioning1, const int acceleration1, const int topSpeed1, const int maximumRange1){
        typeOfVehicle = TypesOfVehicles::ELECTRIC_CAR;
        airConditioning = airConditioning1;
        numberOfSeats = numberOfSeats1;
        model = model1;
        acceleration = acceleration1;
        maximumRange = maximumRange1;
        topSpeed = topSpeed1;
        battery = 100;
        spz = spz1;
        static int electricCarsCount = 1;
        std::stringstream numberOfElectricCars;
        numberOfElectricCars << std::setw(3) << std::setfill('0') << std::to_string(electricCarsCount++);
        identificationNumber = "AA" + numberOfElectricCars.str();
    };
    const std::string& getIdentificationNumber() {
        return identificationNumber;
    }
    std::string showInfo() const;
    std::string getSPZ() const { return spz; };
};

class ElectricBike : public Vehicle {
private:
    int typeOfBike;
public:
    ElectricBike(const int typeOfBike1) {
        if (typeOfBike1 > 3){
            throw std::runtime_error("Failed to construct object.");
        }
        typeOfBike = typeOfBike1;
        typeOfVehicle = TypesOfVehicles::ELECTRIC_BIKE;
        battery = 100; // Predpokladaná plná kapacita batérie
        static int electricBikeCount = 1;
        std::stringstream numberOfElectricBikes;
        numberOfElectricBikes << std::setw(3) << std::setfill('0') << std::to_string(electricBikeCount++);
        identificationNumber = "BB" + numberOfElectricBikes.str();
    }
    std::string showInfo() const;
    int getTypeOfBike() const { return typeOfBike; }
};

#endif //SEMESTRALNYPROJECT_VEHICLE_H
