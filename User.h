#ifndef USER_H
#define USER_H

#include<conio.h>
#include<windows.h>
#include<ctime>
#include"assistance.h"
#include"orderdata.h"
#include"DishClass.h"

class User
{
public:
	//用户菜单
	void UserMenu(int user);
	//用户已点菜品数量
	int DishNum = 0;
	//用户选择的菜品id数组
	int UserDish[ORDERINF_COUNT];
	//用户选择菜品的当前总价
	float TotalPrice = 0;
	//待支付金额
	int bill;

private:
	//用户id
	int UserID;
	//已选菜品
	Dish* orderInf[ORDERINF_COUNT];

	//点餐
	bool OrderDish();
	//结账
	bool Pay();
	//查询单个订单
	bool QueryOrder( Order &order);
	//查询所有订单
	void QueryAllOrder();
	//菜品评分
	bool DishScore();

};

#endif
