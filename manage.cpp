#include"manage.h"

void manage() {
    DishClass DishClass1;
    OrderClass OrderClass1;
    bool flag = true;
    char choice;
    while (flag)
    {
        cout << "---------------------1.��Ʒ����-----------------" << endl;
        cout << "---------------------2.��������-----------------" << endl;
        cout << "---------------------3.�˳�---------------------" << endl;
        cout << "��ѡ��";
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
            cout << "---------------------�˳��ɹ�-------------------" << endl;
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
        cout << "-----------------��������ϵͳ--------------------" << endl;
        cout << "-----------------1.ɾ������---------------------" << endl;
        cout << "-----------------2.չʾ����---------------------" << endl;
        cout << "-----------------3.������һ��-------------------" << endl;
        flag = true;
        cin >> choice1;
        switch (choice1) {
        case '1':
            OrderClass.ShowAll();
            cout << "������Ҫɾ���Ķ����ţ�" << endl;
            //ɾ������
            cin >> temp;
            if (OrderClass.DeleteOrder(temp)) cout << "-------------------ɾ���ɹ�--------------" << endl;
            else cout << "-------------------------û�д˶�����--------------------" << endl;
            break;
        case '2':
            //չʾ���ж���
            OrderClass.ShowAll();
            getchar(); getchar();
            break;
        case '3':
            flag = false;
            cout << "----------------�˳��ɹ�-------------------" << endl;
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
        cout << "-----------------��Ʒ����ϵͳ--------------------" << endl;
        cout << "-----------------1.���Ҳ�Ʒ---------------------" << endl;
        cout << "-----------------2.���Ӳ˵�---------------------" << endl;
        cout << "-----------------3.�޸Ĳ�Ʒ---------------------" << endl;
        cout << "-----------------4.ɾ����Ʒ---------------------" << endl;
        cout << "-----------------5.չʾ��Ʒ---------------------" << endl;
        cout << "-----------------6.������һ��-------------------" << endl;
        cout << "������(1-6,�벻Ҫ������������)��";
        flag = true;
        cin >> choice1;
        cin.clear();
        cin.sync();
        switch (choice1) {
        case '1':
            flag2 = true;
            while (flag2) {
                cout << "------------------���Ҳ�Ʒ----------------------" << endl;
                cout << "-----------------1.ʹ��id����-------------------" << endl;
                cout << "-----------------2.ʹ�ò�������------------------" << endl;
                cout << "-----------------3.�˳�-------------------------" << endl;
                cout << "������(1-3,�벻Ҫ������������)��";
                cin >> choice3;
                switch (choice3) {
                case '1':
                    cout << "�������ѯ��Ʒid:" << endl;
                    //int id;
                    cin >> id;
                    cin.clear();
                    cin.sync();
                    if (DishClass.GetID(id, dish_0)) {
                        cout << "----------------��ѯ�������-----------------" << endl;
                    }
                    else {
                        cout << "------------------û�в�Ʒ-------------------" << endl;
                    }
                    break;
                case '2':
                    cout << "�������ѯ��Ʒ����" << endl;
                    cin >> name;
                    if (DishClass.GetByName(name, dish_0)) {
                        cout << "----------------��ѯ�������-----------------" << endl;
                        cout << dish_0->name << endl;
                    }
                    else
                        cout << "------------------û�в�Ʒ-------------------" << endl;

                    break;
                case '3':
                    flag2 = false;
                    cout << "-----------------�˳��ɹ�------------------" << endl;
                    break;
                }
            }
            break;
        case '2':
            cout << "�������Ʒ��Ϣ" << endl;
            cout << "��Ʒid:";
            cin >> dish.id;
            cout << "������";
            cin >> dish.name;
            cout << "�۸�";
            cin >> dish.price;
            cin.clear();
            cin.sync();
            dish.sales = 0;
            dish.sales = 0;
            dish.scnum = 0;
            dish.score = 0;
            if (DishClass.AddDish(dish)) cout << "---------------��ӳɹ�------------" << endl;
            else cout << "-------------���ʧ��---------------" << endl;
            break;
        case '3':
            flag1 = true;
            while (flag1) {
                cout << "--------------1.�޸Ĳ���-------------" << endl;
                cout << "--------------2.�޸ļ۸�---------------" << endl;
                cout << "--------------3.�˳�---------------" << endl;
                DishClass.ShowAll();
                cout << "������(1-3,�벻Ҫ������������)��";
                cin >> choice2;
                cin.clear();
                cin.sync();
                switch (choice2) {
                case '1':

                    cout << "--------------1.�޸Ĳ���-------------" << endl;
                    cout << "������Ҫ�޸ĵĲ���id:";
                    cin >> id;
                    cout << "�޸ĺ�����֣�";
                    cin >> name;
                    if (DishClass.UpdataName(id, name)) cout << "------------------�޸ĳɹ�-------------" << endl;
                    else cout << "-----------------δ�ҵ���Ʒ,�޸�ʧ��------------------" << endl;
                    break;
                case '2':

                    cout << "--------------2.�޸ļ۸�-------------" << endl;
                    cout << "������Ҫ�޸ĵĲ���id:";
                    cin >> id;
                    cin >> price;
                    cin.clear();
                    cin.sync();
                    if (DishClass.UpdataPrice(id, price)) cout << "------------------�޸ĳɹ�-------------" << endl;
                    else cout << "-----------------δ�ҵ���Ʒ,�޸�ʧ��------------------" << endl;
                    break;
                case '3':
                    flag1 = false;
                    cout << "-------------�����˳��ɹ�---------------" << endl;
                    break;
                }
            }
            break;
        case '4':
            cout << endl;
            DishClass.ShowAll();
            int id;
            cout << endl;
            cout << "������Ҫɾ���Ĳ�Ʒid:";
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
                cout << "--------------1.ֱ��չʾ-------------" << endl;
                cout << "--------------2.������չʾ---------------" << endl;
                cout << "--------------3.������չʾ---------------" << endl;
                cout << "--------------4.�˳�---------------" << endl;
                cout << "������(1-4,�벻Ҫ������������)��";
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
                    cout << "----------------�˳��ɹ�---------------" << endl;
                    break;
                }
            }
            
            break;
        case '6':
            flag = false;
            cout << "----------------�˳��ɹ�---------------" << endl;
            break;
        }
    }
}


/*int main() {
    DishClass dish;
    OrderClass order;
    // string str = "�Ǵ��Ź�";
    // Dish test(2,str,12.9,0,0);
    manage(dish,order);

}*/
