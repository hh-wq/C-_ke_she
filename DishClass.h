#pragma once
#include "DishNode.h"
#include <fstream>

class DishClass {
private:
    DishNOde* head;
    DishNOde* last;//ָ�����һ���ڵ�
    int length;
    void print(Dish p);
    bool OutToFile(DishNOde* p, string str);
    DishNOde* SortBysorce(DishNOde* start);
    DishNOde* mergeBySorce(DishNOde* left, DishNOde* right);
    DishNOde* SortBySales(DishNOde* start);
    DishNOde* mergeBySales(DishNOde* left, DishNOde* right);
public:
    DishClass();
    ~DishClass();
    void ShowAll();
    bool GetID(int id, Dish*& dish);//��ѯ����
    bool GetByName(string name, Dish*& dish);//ͨ��������ѯ
    bool AddDish(Dish dish);//���Ӳ���
    bool DeleteDish(int id);//ɾ������
    bool UpdataScore(int id, int addScore);//��������
    bool UpdataSales(int id);
    bool UpdataName(int id, string name);
    bool UpdataPrice(int id, float name);
    bool ShowByScore();
    bool ShowBySales();
};