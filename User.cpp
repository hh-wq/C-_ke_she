#include "User.h"
#include "Windows.h"

void User::UserMenu(int user)
{
	UserID = user;
	while (1)
	{
		system("cls");
		cout << "----------���ϵͳ----------" << endl << endl;
		cout << "1.���" << endl;
		cout << "2.����" << endl;
		cout << "3.��ʷ����" << endl;
		cout << "4.�˳�" << endl;
		cout << "��������ѡ��Ĺ��ܣ�";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (OrderDish())
				cout << "���Ķ��������ɣ�ף���ò���죡" << endl;
			else
				cout << "��Ϊ��ȡ���㵥" << endl;

			cout << "��������Լ���" << endl;
			while (!_kbhit());
			//UserMenu(UserID);
			break;

		case 2:
			Pay();

			cout << "��������Լ���" << endl;
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
			cout << "��������Լ���" << endl;
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

		cout << endl << "��������ѡ��Ĳ�Ʒ�����(��ż��ûس��������������������룬����0�Խ�������)��";
		cin >> DishID;

		if (!DishID)break;
		else if (DishClass1.GetID(DishID, dish))
		{
			orderInf[DishNum] = dish;
			TotalPrice += dish->price;
			cout << "�ѵ��Ʒ�ܼۣ�" << TotalPrice << "Ԫ" << endl;
			cout << "��ѡ��Ʒ��";
			for (int i = 0; i <= DishNum; i++)  //��ӡȫ���ѵ��
				cout << orderInf[i]->name << dish->price << "Ԫ" << endl;
		}
		else
			cout << "����������������������룡" << endl;
	}
	cout << "��ȷ�����ĵ㵥��ȷ���밴�������ȡ���밴ESC";
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
	cout << "��֧��������" << endl;
	for (int i = 1; i <= OrderID_Arr[0]; i++)
	{
		order_class.GetID(OrderID_Arr[i], &order);
		if (!order.os) {
			QueryOrder(order);
			cout << "��֧����" << bill << "Ԫ";
		}
	}

	cout << "\n1.����֧��" << endl
		<< "2.�Ժ�֧��" << endl
		<< "�����룺" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "����yģ��֧����";
		if (_getch() == 'y' || _getch() == 'Y')
		{
			cout << "֧���ɹ���" << endl;
			order_class.Pay(order.id);
			
			cout << "�Ƿ�Ϊ��Ʒ����,��������������֣�ȡ���밴ESC" << endl;
			if (_getch() != 27)
				DishScore();
			return true;
		}
		else
			cout << "֧��ʧ��";
		return Pay();   //����֧�����棬�����ص���������boolֵ
	case 2:
		cout << "��ȡ��֧��";
		return false;
	}
}

bool User::QueryOrder( Order &order)
{
	
	//Order order;
	//if (!order_class.GetID(OrderID, &order))
	//{
	//	cout << "����������" << endl;
	//	return false;
	//}
	//else
	//{

	cout << "����ID��" << order.id << "\t֧��״̬��" << ((order.os)?("��֧��"):("δ֧��"))
			<< "\tʱ�䣺" << order.time.year << "." << order.time.month << "." << order.time.day << "." << endl;
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
	/*cout << "1.�鿴��������" << endl
		<< "2.�������˵�" << endl
		<< "�����룺" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "��������Ҫ�鿴����Ķ���id��";
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
				cout << dish->name << dish->price << "Ԫ" << endl;
			}
			cout << "��ESC����" << endl;
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
		for (int j = 0; j < i; j++)  //�жϲ��Ƿ��Ѿ����۹�
			if (orderInf[j]->id == orderInf[i]->id)
			{
				flag = 1;
				break;
			}
		if (!flag)
		{
			cout << orderInf[i]->id << "��Ʒ����" << orderInf[i]->name << "��Ʒ�۸�" << orderInf[i]->price;
			cout << "�����֣�0��5�֣���";
			int sorce;
			cin >> sorce;
			DishClass1.UpdataSales(orderInf[i]->id);
			DishClass1.UpdataScore(orderInf[i]->id, sorce);
		}
	}
	cout << "��л�������ۣ���ӭ�´ι��٣�" << endl;
	return true;
}


