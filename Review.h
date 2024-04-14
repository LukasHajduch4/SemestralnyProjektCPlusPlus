//
// Created by Lukas Hajduch on 12/16/2023.
//

#ifndef SEMESTRALNYPROJECT_REVIEW_H
#define SEMESTRALNYPROJECT_REVIEW_H

#include <string>

class Review {
private:
    std::string comment;
    float rating; // Rating from 1 to 5

public:
    Review(const std::string& comment, float rating);
    const std::string& getComment() const;
    float getRating() const;
};

#endif //SEMESTRALNYPROJECT_REVIEW_H