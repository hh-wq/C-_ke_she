#pragma once
//2022/6/20
#ifndef ORDER_SYSTEM_H
#define ORDER_SYSTEM_H


#include <iostream>
#include <string.h>
using namespace std;

#define CUSTOMER_NAME_LENGTH 10
#define ORDERINF_COUNT 50
#define DISH_NAME_LENGTH 30

struct Customer {
	int id;
	char name[CUSTOMER_NAME_LENGTH];
	int password;
};	//顾客
struct Time {
	int year;
	int month;
	int day;
};	//时间
struct Order {
	int id;
	Time time;
	int cid;
	bool os;
	int orderInf[ORDERINF_COUNT];
	int n;
};	//订单
struct Dish {
	int id;
	string name;
	float price;
	float score;
	int scnum;
	int sales;
	Dish(int id, string name, float price, float score = 0, int scnum = 0) {
		this->id = id;
		this->name = name;
		this->price = price;
		this->score = score;
		this->scnum = scnum;
		this->sales = sales;
	};
	Dish() {};
};	//菜品
#endif