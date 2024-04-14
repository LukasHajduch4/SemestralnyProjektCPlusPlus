//
// Created by Lukas Hajduch on 12/15/2023.
//
#include <string>
#include <sstream>
#include "User.h"

User::User(const std::string& name, float money1) {
    static int userCount = 1;
    if (name.empty()) {
        username = "RandomGeneratedUsername" + std::to_string(userCount++);
    }
    else{
        username = name;
    }
    money = money1;
    reserved = false;
}

bool User::addRide(const std::string& infoAboutRide) {
    //format of infoAboutRide: <startingLocation>:<destination>:<pricePer100Km>:<routeLength>:<brandOfCar>:<color>:<availableSeatsForReservation>
    std::stringstream ss(infoAboutRide);
    std::string oneElement;
    std::string startLocation, destinationLocation, brandOfCar, color;
    int counter = 0, pricePerHundredKilometers = 0, routeLength = 0, availableSeatsForReservation = 0;
    while (getline(ss, oneElement, ':')){
        if (oneElement.empty()){
            return false;
        }
        switch (counter){
            case 0:
                startLocation = oneElement;
                break;
            case 1:
                destinationLocation = oneElement;
                break;
            case 2:
                pricePerHundredKilometers = std::stoi(oneElement);
                break;
            case 3:
                routeLength = std::stoi(oneElement);
                break;
            case 4:
                brandOfCar = oneElement;
                break;
            case 5:
                color = oneElement;
                break;
            case 6:
                availableSeatsForReservation = std::stoi(oneElement);
                break;
            default:
                break;
        }
        counter++;
    }
    static int rideCount = 1;
    std::string rideID = "ID" + std::to_string(rideCount++);
    Ride oneRide = Ride(rideID, startLocation,destinationLocation,pricePerHundredKilometers,routeLength,brandOfCar,color,availableSeatsForReservation);
    rides.push_back(oneRide);
    return true;
}

bool User::removeRide(const std::string& rideID) {
    int counter = 0;
    for (auto it = rides.begin(); it != rides.end();) {
        if (rides.at(counter).getRideIdentificationNumber() == rideID) {
            rides.erase(it);
            return true;
        } else {
            ++it;
        }
        counter++;
    }
    return false;
}

Ride User::findRideWithId(const std::string &rideID) const {
    int counter = 0;
    for (auto it = rides.begin(); it != rides.end();) {
        if (rides.at(counter).getRideIdentificationNumber() == rideID) {
            return rides.at(counter);
        } else {
            ++it;
        }
        counter++;
    }
    std::string emptyString = "-";
    return {emptyString, emptyString,emptyString,0,0,emptyString,emptyString,0};
}

bool User::addReview(const std::string& review) {
    // in format "<number>:<comment>"
    size_t whereIsDoubleColon = review.find(':');
    if (whereIsDoubleColon == 0 || whereIsDoubleColon == std::string::npos){
        return false;
    }
    std::string rating = review.substr(0,whereIsDoubleColon);
    std::string comment = review.substr(whereIsDoubleColon+1, review.size());
    if(comment.empty()){
        return false;
    }
    Review newReview(comment, std::stof(rating));
    reviews.push_back(newReview);
    return true;
}

float User::averageRating() const {
    float summary = 0;
    for (const Review& oneReview : reviews){
        summary += oneReview.getRating();
    }
    if (!reviews.empty()){
        float sum = summary/reviews.size();
        return sum;
    }
    return -1.00000;
}
const std::string& User::getUsername() const {
    return username;
}

const std::vector<Ride> User::getRides() const {
    return rides;
}
std::string User::bestRating() const{
    float bestReview = 0;
    std::string commentOfTheBestReview;
    for (const Review& oneReview : reviews){
        if (bestReview < oneReview.getRating()){
            commentOfTheBestReview = oneReview.getComment();
            bestReview = oneReview.getRating();
        }
    }
    if (bestReview > 0){
        std::stringstream ss1;
        ss1 << bestReview << ":" << commentOfTheBestReview;
        return ss1.str();
    }
    return "No ratings for this user";
}
