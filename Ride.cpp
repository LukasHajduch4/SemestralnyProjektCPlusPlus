//
// Created by Lukas Hajduch on 12/15/2023.
//
#include <sstream>
#include "Ride.h"

Ride::Ride(std::string& id, std::string& start, std::string& end, int price, int length, std::string& brandOfCar1, std::string& color1, int availableSeats)
        : rideIdentificationNumber(id), startingLocation(start), destination(end), pricePer100Km(price), routeLength(length), brandOfCar(brandOfCar1), color(color1), availableSeatsForReservation(availableSeats){}

const std::string& Ride::getStartingLocation() const {
    return startingLocation;
}

const std::string& Ride::getDestination() const {
    return destination;
}

int Ride::getPricePer100Km() const {
    return pricePer100Km;
}

int Ride::getRouteLength() const {
    return routeLength;
}

const std::string& Ride::getBrandOfCar() const{
    return brandOfCar;
}
const std::string& Ride::getColor() const{
    return color;
}
int Ride::getAvailableSeatsForReservation() const {
    return availableSeatsForReservation;
}
std::string Ride::getRideIdentificationNumber() const {
    return rideIdentificationNumber;
}
std::string Ride::showInfoAboutRide() const {
    std::stringstream infoAboutRide;
    infoAboutRide << RIDE_ID_LABEL << rideIdentificationNumber << std::endl;
    infoAboutRide << START_LOCATION_LABEL << startingLocation << std::endl;
    infoAboutRide << DESTINATION_LABEL << destination << std::endl;
    infoAboutRide << PRICE_PER_100_KM_LABEL << pricePer100Km << std::endl;
    infoAboutRide << ROUTE_LENGTH_LABEL << routeLength << std::endl;
    infoAboutRide << BRAND_OF_CAR_LABEL << brandOfCar << std::endl;
    infoAboutRide << COLOR_LABEL << color;
    return infoAboutRide.str();
}