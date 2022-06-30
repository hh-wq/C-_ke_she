#pragma once
#include "DishNode.h"
#include <fstream>

class DishClass {
private:
    DishNOde* head;
    DishNOde* last;//指向最后一个节点
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
    bool GetID(int id, Dish*& dish);//查询菜谱
    bool GetByName(string name, Dish*& dish);//通过菜名查询
    bool AddDish(Dish dish);//增加菜谱
    bool DeleteDish(int id);//删除菜谱
    bool UpdataScore(int id, int addScore);//更新评分
    bool UpdataSales(int id);
    bool UpdataName(int id, string name);
    bool UpdataPrice(int id, float name);
    bool ShowByScore();
    bool ShowBySales();
};