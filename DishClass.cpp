#pragma once
#include "DishClass.h"
string dish_path = "dish.txt";

DishClass::DishClass() {
    head = new DishNOde();
    length = 0;
    fstream file;
    file.open(dish_path, ios::in);
    if (!file.is_open()) {
        cout << "read error!" << endl;
        return;
    }
    Dish dish;
    DishNOde* p = head;
    //�ļ��ж�ȡ����
    while (!file.eof()) {
        file >> dish.id >> dish.name >> dish.price >> dish.score >> dish.scnum >> dish.sales;
        //  if (file.good()) {
        if (file.good()) {
            p->next = new DishNOde(dish);
            p = p->next;
            last = p;
            length++;
        }

        // }
    }
    file.close();
}


bool DishClass::OutToFile(DishNOde* p, string str) {//д���ļ���
    fstream file;
    file.open(str, ios::out | ios::app);
    if (!file.is_open()) {
        cout << "failed" << endl;
        return false;
    }

    file << p->dish_inf.id << " " << p->dish_inf.name << " " << p->dish_inf.price << " " <<
        p->dish_inf.score << " " << p->dish_inf.scnum << " " << p->dish_inf.sales << endl;
    return true;
}

DishNOde* DishClass::SortBysorce(DishNOde* start)
{
    if (start == NULL || start->next == NULL) return start;

    DishNOde* slow = start;
    DishNOde* fast = start->next;
    //Ѱ�ҶϿ���
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //�ݹ�ָ�
    DishNOde* right = SortBysorce(slow->next);
    slow->next = NULL;//�ָ�
    DishNOde* left = SortBysorce(start);
    return mergeBySorce(left, right);
}

DishNOde* DishClass::mergeBySorce(DishNOde* left, DishNOde* right)
{
    DishNOde temp, * q;
    q = &temp;
    //�鲢
    while (left != NULL && right != NULL) {
        if (left->dish_inf.score >= right->dish_inf.score) {
            q->next = left;
            left = left->next;
        }
        else {
            q->next = right;
            right = right->next;
        }
        q = q->next;
    }
    if (left != NULL) q->next = left;
    if (right != NULL) q->next = right;
    return temp.next;
}

DishNOde* DishClass::SortBySales(DishNOde* start)
{
    if (start == NULL || start->next == NULL) return start;

    DishNOde* slow = start;
    DishNOde* fast = start->next;
    //Ѱ�ҶϿ���
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //�ݹ�ָ�
    DishNOde* right = SortBySales(slow->next);
    slow->next = NULL;//�ָ�
    DishNOde* left = SortBySales(start);
    return mergeBySales(left, right);
}

DishNOde* DishClass::mergeBySales(DishNOde* left, DishNOde* right)
{
    DishNOde temp, * q;
    q = &temp;
    //�鲢
    while (left != NULL && right != NULL) {
        if (left->dish_inf.sales >= right->dish_inf.sales) {
            q->next = left;
            left = left->next;
        }
        else {
            q->next = right;
            right = right->next;
        }
        q = q->next;
    }
    if (left != NULL) q->next = left;
    if (right != NULL) q->next = right;
    return temp.next;
}




void DishClass::print(Dish dish) {
    char str_id[3], str_price[5], str_score[5], str_scum[5], str_sales[5];

    sprintf_s(str_id, "%d", dish.id);
    sprintf_s(str_price, "%.1f", dish.price);
    sprintf_s(str_score, "%.1f", dish.score);
    sprintf_s(str_scum, "%d", dish.scnum);
    sprintf_s(str_sales, "%d", dish.sales);
    //string str = str_id;

    cout << "��Ʒ�ţ�" << str_id << " ��Ʒ��:";
    cout << dish.name << " ��Ʒ�۸�:" << str_price << " ��Ʒ����:"
        << str_score << " ��������:" << str_scum << " ����:" << str_sales << endl;
}

DishClass::~DishClass() {
    fstream file;
    file.open(dish_path, ios::out | ios::trunc);
    if (!file.is_open()) {
        cout << "---------open failed--------" << endl;
        return;
    }
    file.close();
    //����д���ļ�
    DishNOde* q = head->next;//����ָ��
    for (int i = 0; i < length && q != NULL; q = q->next) {
        OutToFile(q, dish_path);
    }
}

bool DishClass::GetID(int id, Dish*& dish) {//ͨ��ID��ѯ����
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            dish = p->GetDish();
            print(p->dish_inf);
            return true;
        }
        p = p->next;
    }
    return false;
}

bool DishClass::GetByName(string name, Dish*& dish)
{
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (!name.compare(p->dish_inf.name)) {
            dish = p->GetDish();
            print(p->dish_inf);
            return true;
        }
        p = p->next;
    }
    return false;
}

bool DishClass::AddDish(Dish dish) {//���Ӳ˵�
    DishNOde* p = new DishNOde(dish);
    Dish *temp = new Dish;
    if (GetID(dish.id, temp)) 
    { 
        delete temp;
        return 0; 
    }
    last->next = p;
    last = p;
    length++;
    delete p;
    delete temp;
    return true;
}

bool DishClass::DeleteDish(int id) {//ɾ����Ʒ
    DishNOde* p;
    DishNOde* q;
    q = head;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            q->next = p->next;
            p->next = NULL;
            length--;
            return true;
        }
        p = p->next;
        q = q->next;
    }
    return false;
}

bool DishClass::UpdataScore(int id, int addSorce) {//��������
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            int oldScore;
            oldScore = p->GetDish()->score;
            p->GetDish()->score = (oldScore * p->GetDish()->scnum + addSorce) / (++p->GetDish()->scnum);
            return true;
        }
        p = p->next;
    }
    return false;
}

bool DishClass::UpdataSales(int id)
{
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            p->GetDish()->sales++;
            return true;
        }
        p = p->next;
    }
    return false;
}

void DishClass::ShowAll() {
    DishNOde* p;
    p = head->next;
    for (int i = 0; i < length; i++) {
        print(p->dish_inf);
        p = p->next;
    }
}

bool DishClass::UpdataName(int id, string name) {
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            p->change(name);
            return true;
        }
        p = p->next;
    }
    return false;
}
bool DishClass::UpdataPrice(int id, float price) {
    DishNOde* p = new DishNOde;
    p = head->next;
    for (int i = 0; i < length; i++) {
        if (id == p->dish_inf.id) {
            p->GetDish()->price = price;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool DishClass::ShowByScore()
{
    DishNOde* p = SortBysorce(head->next);
    if (p == NULL || p->next == NULL) cout << "-------------������û�в�------------" << endl;
    head->next = p;
    cout << "------------�������------------" << endl;
    ShowAll();
    return 1;
}

bool DishClass::ShowBySales()
{
    DishNOde* p = SortBySales(head->next);
    if (p == NULL || p->next == NULL) cout << "-------------������û�в�------------" << endl;
    head->next = p;
    cout << "------------�������------------" << endl;
    ShowAll();
    return 1;
}
