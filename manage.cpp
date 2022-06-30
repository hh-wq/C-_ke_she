#include"manage.h"

void manage() {
    DishClass DishClass1;
    OrderClass OrderClass1;
    bool flag = true;
    char choice;
    while (flag)
    {
        cout << "---------------------1.菜品管理-----------------" << endl;
        cout << "---------------------2.订单管理-----------------" << endl;
        cout << "---------------------3.退出---------------------" << endl;
        cout << "请选择：";
        cin >> choice;
        switch (choice)
        {
        case '1':
            manage_dish(DishClass1);
            break;
        case '2':
            manage_order(OrderClass1);
        case '3':
            flag = false;
            cout << "---------------------退出成功-------------------" << endl;
        default:
            break;
        }
    }
}


void manage_order(OrderClass& OrderClass) {
    char choice1;
    int temp;
    bool flag = true;
    bool flag1 = true;
    bool flag2 = true;
    char a;
    string str;
    double temp1, temp2;
    while (flag) {
        system("cls");
        cout << endl;
        cout << "-----------------订单管理系统--------------------" << endl;
        cout << "-----------------1.删除订单---------------------" << endl;
        cout << "-----------------2.展示订单---------------------" << endl;
        cout << "-----------------3.返回上一级-------------------" << endl;
        flag = true;
        cin >> choice1;
        switch (choice1) {
        case '1':
            OrderClass.ShowAll();
            cout << "请输入要删除的订单号：" << endl;
            //删除订单
            cin >> temp;
            if (OrderClass.DeleteOrder(temp)) cout << "-------------------删除成功--------------" << endl;
            else cout << "-------------------------没有此订单号--------------------" << endl;
            break;
        case '2':
            //展示所有订单
            OrderClass.ShowAll();
            getchar(); getchar();
            break;
        case '3':
            flag = false;
            cout << "----------------退出成功-------------------" << endl;
            break;
        }
    }
}


void manage_dish(DishClass& DishClass) {
    char choice1, choice2, choice3, choice4;
    Dish dish;
    Dish* dish_0 = new Dish();
    float price;
    int id;
    string name;
    int* time = new int[3];
    bool flag = true;
    bool flag1 = true;
    bool flag2 = true;
    while (flag) {
        system("cls");
        cout << "-----------------菜品管理系统--------------------" << endl;
        cout << "-----------------1.查找菜品---------------------" << endl;
        cout << "-----------------2.增加菜单---------------------" << endl;
        cout << "-----------------3.修改菜品---------------------" << endl;
        cout << "-----------------4.删除菜品---------------------" << endl;
        cout << "-----------------5.展示菜品---------------------" << endl;
        cout << "-----------------6.返回上一级-------------------" << endl;
        cout << "请输入(1-6,请不要输入其他数据)：";
        flag = true;
        cin >> choice1;
        cin.clear();
        cin.sync();
        switch (choice1) {
        case '1':
            flag2 = true;
            while (flag2) {
                cout << "------------------查找菜品----------------------" << endl;
                cout << "-----------------1.使用id查找-------------------" << endl;
                cout << "-----------------2.使用菜名查找------------------" << endl;
                cout << "-----------------3.退出-------------------------" << endl;
                cout << "请输入(1-3,请不要输入其他数据)：";
                cin >> choice3;
                switch (choice3) {
                case '1':
                    cout << "请输入查询菜品id:" << endl;
                    //int id;
                    cin >> id;
                    cin.clear();
                    cin.sync();
                    if (DishClass.GetID(id, dish_0)) {
                        cout << "----------------查询结果如上-----------------" << endl;
                    }
                    else {
                        cout << "------------------没有菜品-------------------" << endl;
                    }
                    break;
                case '2':
                    cout << "请输入查询菜品名：" << endl;
                    cin >> name;
                    if (DishClass.GetByName(name, dish_0)) {
                        cout << "----------------查询结果如上-----------------" << endl;
                        cout << dish_0->name << endl;
                    }
                    else
                        cout << "------------------没有菜品-------------------" << endl;

                    break;
                case '3':
                    flag2 = false;
                    cout << "-----------------退出成功------------------" << endl;
                    break;
                }
            }
            break;
        case '2':
            cout << "请输入菜品信息" << endl;
            cout << "菜品id:";
            cin >> dish.id;
            cout << "菜名：";
            cin >> dish.name;
            cout << "价格：";
            cin >> dish.price;
            cin.clear();
            cin.sync();
            dish.sales = 0;
            dish.sales = 0;
            dish.scnum = 0;
            dish.score = 0;
            if (DishClass.AddDish(dish)) cout << "---------------添加成功------------" << endl;
            else cout << "-------------添加失败---------------" << endl;
            break;
        case '3':
            flag1 = true;
            while (flag1) {
                cout << "--------------1.修改菜名-------------" << endl;
                cout << "--------------2.修改价格---------------" << endl;
                cout << "--------------3.退出---------------" << endl;
                DishClass.ShowAll();
                cout << "请输入(1-3,请不要输入其他数据)：";
                cin >> choice2;
                cin.clear();
                cin.sync();
                switch (choice2) {
                case '1':

                    cout << "--------------1.修改菜名-------------" << endl;
                    cout << "请输入要修改的菜名id:";
                    cin >> id;
                    cout << "修改后的名字：";
                    cin >> name;
                    if (DishClass.UpdataName(id, name)) cout << "------------------修改成功-------------" << endl;
                    else cout << "-----------------未找到菜品,修改失败------------------" << endl;
                    break;
                case '2':

                    cout << "--------------2.修改价格-------------" << endl;
                    cout << "请输入要修改的菜名id:";
                    cin >> id;
                    cin >> price;
                    cin.clear();
                    cin.sync();
                    if (DishClass.UpdataPrice(id, price)) cout << "------------------修改成功-------------" << endl;
                    else cout << "-----------------未找到菜品,修改失败------------------" << endl;
                    break;
                case '3':
                    flag1 = false;
                    cout << "-------------查找退出成功---------------" << endl;
                    break;
                }
            }
            break;
        case '4':
            cout << endl;
            DishClass.ShowAll();
            int id;
            cout << endl;
            cout << "请输入要删除的菜品id:";
            cin >> id;
            cin.clear();
            cin.sync();
            DishClass.DeleteDish(id);
            break;
        case '5':
            cout << endl;
            flag1 = true;
            choice4 = '0';
            while (flag1) {
                system("cls");
                cout << "--------------1.直接展示-------------" << endl;
                cout << "--------------2.按评分展示---------------" << endl;
                cout << "--------------3.按销量展示---------------" << endl;
                cout << "--------------4.退出---------------" << endl;
                cout << "请输入(1-4,请不要输入其他数据)：";
                cin >> choice4;
                switch (choice4) {
                case '1':
                    DishClass.ShowAll();
                    getchar(); getchar();
                    break;
                case '2':
                    DishClass.ShowByScore();
                    getchar(); getchar();
                    break;
                case '3':
                    DishClass.ShowBySales();
                    getchar(); getchar();
                    break;
                case '4':
                    flag1 = false;
                    cout << "----------------退出成功---------------" << endl;
                    break;
                }
            }
            
            break;
        case '6':
            flag = false;
            cout << "----------------退出成功---------------" << endl;
            break;
        }
    }
}


/*int main() {
    DishClass dish;
    OrderClass order;
    // string str = "糖醋排骨";
    // Dish test(2,str,12.9,0,0);
    manage(dish,order);

}*/
