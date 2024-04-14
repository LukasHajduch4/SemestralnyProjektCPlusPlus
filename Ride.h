//
// Created by Lukas Hajduch on 12/15/2023.
//

#ifndef SEMESTRALNYPROJECT_RIDE_H
#define SEMESTRALNYPROJECT_RIDE_H

#include <string>
#include <vector>
const std::string RIDE_ID_LABEL = "Ride ID: ";
const std::string START_LOCATION_LABEL = "Start location: ";
const std::string DESTINATION_LABEL = "Destination: ";
const std::string PRICE_PER_100_KM_LABEL = "Price per 100 km: ";
const std::string ROUTE_LENGTH_LABEL = "Route length: ";
const std::string BRAND_OF_CAR_LABEL = "Brand of car: ";
const std::string COLOR_LABEL = "Color: ";

class Ride {
private:
    std::string rideIdentificationNumber;
    std::string startingLocation;
    std::string destination;
    int pricePer100Km;
    int routeLength;
    std::string brandOfCar;
    std::string color;
    int availableSeatsForReservation;
    std::vector<std::string> idOfPassengers;

public:
    Ride(std::string& id, std::string& start, std::string& end, int price, int length, std::string& brandOfCar1, std::string& color1, int availableSeats);

    const std::string& getStartingLocation() const;
    const std::string& getDestination() const;
    int getPricePer100Km() const;
    int getRouteLength() const;
    const std::string& getBrandOfCar() const;
    const std::string& getColor() const;
    int getAvailableSeatsForReservation() const;
    std::string getRideIdentificationNumber() const;
    std::string showInfoAboutRide() const;
    void setAvailableSeatsForReservation(int newCountOfAvailableSeats){ availableSeatsForReservation = newCountOfAvailableSeats;}
    void addIdOfPassengers(const std::string& idOfPassenger){ idOfPassengers.push_back(idOfPassenger);}
};

#endif //SEMESTRALNYPROJECT_RIDE_H
