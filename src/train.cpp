// Copyright 2021 NNTU-CS
#include "train.h"

Train::Car::Car(bool light_state) : light(light_state), next(nullptr), prev(nullptr) {}

Train::Train() : count_op_(0), first_(nullptr), real_length_(0) {}

Train::~Train() {
    Clear();
}

void Train::AddCar(bool light) {
    Car* new_car = new Car(light);

    if (first_ == nullptr) {
        first_ = new_car;
        new_car->next = new_car;
        new_car->prev = new_car;
    } else {
        Car* last = first_->prev;
        last->next = new_car;
        new_car->prev = last;
        new_car->next = first_;
        first_->prev = new_car;
    }
    real_length_++;
}

void Train::Clear() {
    if (first_ == nullptr) return;

    Car* current = first_;
    Car* next_car = nullptr;

    do {
        next_car = current->next;
        delete current;
        current = next_car;
    } while (current != first_);

    first_ = nullptr;
    real_length_ = 0;
    count_op_ = 0;
}

int Train::GetLength() {
    if (first_ == nullptr) return 0;
    if (first_->next == first_) return 1;

    count_op_ = 0;



    Car* current = first_;
    Car* start = first_;

    current->light = true;

    bool found = false;

    while (!found) {
        while (true) {
            count_op_++;
            current = current->next;

            if (current->light) {
                if (current == start) {
                    found = true;
                    break;
                } else {
                    current->light = false;
                    break;
                }
            }
        }
    }

    int length = 0;
    current = first_;
    do {
        length++;
        current = current->next;
        count_op_++;
    } while (current != first_);

    count_op_--;

    return length;
}

int Train::GetOpCount() const {
    return count_op_;
}

int Train::GetRealLength() const {
    return real_length_;
}
