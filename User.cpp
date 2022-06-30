#include "User.h"
#include "Windows.h"

void User::UserMenu(int user)
{
	UserID = user;
	while (1)
	{
		system("cls");
		cout << "----------点餐系统----------" << endl << endl;
		cout << "1.点餐" << endl;
		cout << "2.结账" << endl;
		cout << "3.历史订单" << endl;
		cout << "4.退出" << endl;
		cout << "请输入您选择的功能：";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (OrderDish())
				cout << "您的订单已生成，祝您用餐愉快！" << endl;
			else
				cout << "已为您取消点单" << endl;

			cout << "按任意键以继续" << endl;
			while (!_kbhit());
			//UserMenu(UserID);
			break;

		case 2:
			Pay();

			cout << "按任意键以继续" << endl;
			while (!_kbhit());
			//UserMenu(UserID);
			break;

		case 3:
			QueryAllOrder();
			//UserMenu(UserID);
			break;

		case 4:
			return;

		default:
			cout << "Invalid choice!" << endl;
			cout << "按任意键以继续" << endl;
			while (!_kbhit());
			//UserMenu(UserID);
			break;
		}
	}
}

bool User::OrderDish()
{
	system("cls");

	DishClass DishClass1;
	DishClass1.ShowAll();

	for (DishNum = 0; DishNum < 50; DishNum++)
	{
		Dish* dish;
		int DishID;

		cout << endl << "请输入您选择的菜品的序号(序号间用回车隔开，如需多份请多次输入，输入0以结束输入)：";
		cin >> DishID;

		if (!DishID)break;
		else if (DishClass1.GetID(DishID, dish))
		{
			orderInf[DishNum] = dish;
			TotalPrice += dish->price;
			cout << "已点菜品总价：" << TotalPrice << "元" << endl;
			cout << "已选菜品：";
			for (int i = 0; i <= DishNum; i++)  //打印全部已点菜
				cout << orderInf[i]->name << dish->price << "元" << endl;
		}
		else
			cout << "您输入序号有误，请重新输入！" << endl;
	}
	cout << "请确认您的点单，确认请按任意键，取消请按ESC";
	if (_getch() == 27)return false;
	else
	{
		Order order;
		order.id = time(0);
		SYSTEMTIME sysTime;
		ZeroMemory(&sysTime, sizeof(sysTime));
		GetLocalTime(&sysTime);
		order.time.year = sysTime.wYear;
		order.time.month = sysTime.wMonth;
		order.time.day = sysTime.wDay;
		order.cid = UserID;
		order.os = false;
		order.n = DishNum;
		bill = TotalPrice;

		for (int i = 0; i < DishNum; i++)
			order.orderInf[i] = orderInf[i]->id;

		OrderClass order_class;
		order_class.AddOrder(order);
		return true;
	}
}

bool User::Pay()
{
	system("cls");

	OrderClass order_class;
	int* OrderID_Arr;
	Order order;
	OrderID_Arr = order_class.GetOrder(UserID);
	cout << "待支付订单：" << endl;
	for (int i = 1; i <= OrderID_Arr[0]; i++)
	{
		order_class.GetID(OrderID_Arr[i], &order);
		if (!order.os) {
			QueryOrder(order);
			cout << "待支付：" << bill << "元";
		}
	}

	cout << "\n1.立即支付" << endl
		<< "2.稍后支付" << endl
		<< "请输入：" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "输入y模拟支付：";
		if (_getch() == 'y' || _getch() == 'Y')
		{
			cout << "支付成功！" << endl;
			order_class.Pay(order.id);
			
			cout << "是否为菜品评分,按任意键进入评分，取消请按ESC" << endl;
			if (_getch() != 27)
				DishScore();
			return true;
		}
		else
			cout << "支付失败";
		return Pay();   //返回支付界面，并返回迭代函数的bool值
	case 2:
		cout << "已取消支付";
		return false;
	}
}

bool User::QueryOrder( Order &order)
{
	
	//Order order;
	//if (!order_class.GetID(OrderID, &order))
	//{
	//	cout << "订单不存在" << endl;
	//	return false;
	//}
	//else
	//{

	cout << "订单ID：" << order.id << "\t支付状态：" << ((order.os)?("已支付"):("未支付"))
			<< "\t时间：" << order.time.year << "." << order.time.month << "." << order.time.day << "." << endl;
		return true;
	//}
}

void User::QueryAllOrder()
{
	system("cls");

	OrderClass order_class;
	Order order;
	int* OrderID_Arr;
	OrderID_Arr = order_class.GetOrder(UserID);
	for (int i = 1; i <= OrderID_Arr[0]; i++)
	{
		order_class.GetID(OrderID_Arr[i], &order);
		
			QueryOrder(order);
	}
	getchar();	getchar();
	//order_class.ShowAll();
	/*cout << "1.查看订单详情" << endl
		<< "2.返回主菜单" << endl
		<< "请输入：" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "请输入需要查看详情的订单id：";
		int order_id;
		cin >> order_id;
		Order* order = NULL;
		if (QueryOrder(order_id, order_class))
		{
			system("cls");
			order_class.GetID(order_id, order);
			for (int i = 0; i < order->n; i++)
			{
				DishClass DishClass1;
				Dish* dish;
				DishClass1.GetID(order->orderInf[i], dish);
				cout << dish->name << dish->price << "元" << endl;
			}
			cout << "按ESC返回" << endl;
			while (1)
				if (_getch() != 27)
					break;
			QueryAllOrder();
		}
	}*/
}

bool User::DishScore()
{
	system("cls");

	DishClass DishClass1;
	for (int i = 0; i < DishNum; i++)
	{
		int flag = 0;
		Dish* dish;
		for (int j = 0; j < i; j++)  //判断菜是否已经评价过
			if (orderInf[j]->id == orderInf[i]->id)
			{
				flag = 1;
				break;
			}
		if (!flag)
		{
			cout << orderInf[i]->id << "菜品名：" << orderInf[i]->name << "菜品价格：" << orderInf[i]->price;
			cout << "请评分（0到5分）：";
			int sorce;
			cin >> sorce;
			DishClass1.UpdataSales(orderInf[i]->id);
			DishClass1.UpdataScore(orderInf[i]->id, sorce);
		}
	}
	cout << "感谢您的评价，欢迎下次光临！" << endl;
	return true;
}


