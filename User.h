//
// Created by Lukas Hajduch on 12/15/2023.
//

#ifndef SEMESTRALNYPROJECT_USER_H
#define SEMESTRALNYPROJECT_USER_H

#include <string>
#include <vector>
#include "Ride.h"
#include "Review.h"

class User {
private:
    std::string username;
    std::vector<Ride> rides;
    std::vector<Review> reviews;
    bool reserved;
    float money;
public:
    User(const std::string& name, float money1);
    bool addRide(const std::string& infoAboutRide);
    bool removeRide(const std::string& rideID);
    Ride findRideWithId(const std::string& rideID) const;
    bool addReview(const std::string& review);
    float averageRating() const;
    const std::string& getUsername() const;
    const std::vector<Ride> getRides() const;
    std::string bestRating() const;
    float getMoney() const { return money; }
    void setMoney(float newAmount){ money = newAmount; }
    bool getReservedRide() const{ return reserved; }
    void setReservedRide(bool reserved1){ reserved = reserved1; }
};


#endif //SEMESTRALNYPROJECT_USER_H
