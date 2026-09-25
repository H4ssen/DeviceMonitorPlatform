#pragma once

#include <cstdint>
#include <utility>

class Reading {

    public:

    explicit Reading(double v, uint64_t t) : value_(v), timestamp_(t) {}

    double getValue() const {return value_;}
    double getTimestamp() const {return timestamp_;}


    private:
        double value_;
        uint64_t timestamp_;
};