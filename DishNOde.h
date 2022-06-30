#pragma once
#include "assistance.h"
class DishNOde {
public:
    Dish dish_inf;
    DishNOde* next;
    DishNOde();
    DishNOde(Dish dish, DishNOde* nextprt = NULL);
    Dish* GetDish();
    void change(string name);
};