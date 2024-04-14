//
// Created by Lukas Hajduch on 12/16/2023.
//
#include "Review.h"

Review::Review(const std::string& comment, float rating)
        : comment(comment), rating(rating) {}

const std::string& Review::getComment() const {
    return comment;
}

float Review::getRating() const {
    return rating;
}