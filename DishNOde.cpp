#pragma once
#include "DishNOde.h"
DishNOde::DishNOde() {
    next = NULL;
}

DishNOde::DishNOde(Dish dish, DishNOde* nextprt) {
    this->dish_inf = dish;
    next = nextprt;
}

void DishNOde::change(string name) {
    dish_inf.name = name;
}

Dish* DishNOde::GetDish() {
    return &dish_inf;
}