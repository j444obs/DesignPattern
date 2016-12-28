// src_Observer.cpp : 定义控制台应用程序的入口点。
//
#include"Observer.h"
#include <iostream>
#include <algorithm>
using namespace std;
 
 void ObserveObject::RemoveObserver(Observer *pObserver)
 {
	 //定义一个迭代器
     list<Observer*>::iterator iter;
     iter = find(ListObserver.begin(), ListObserver.end(), pObserver);
     //找到要移除的迭代器位置
     if (ListObserver.end() != iter){
		 ListObserver.erase(iter);
     }
     cout << "  移除观察器成功！\n";
 }
 void ObserveObject::AddObserver(Observer *pObserver)
 {
	 cout << " 添加观察器成功！\n";
	 //list种添加新的观察器
	 ListObserver.push_back(pObserver);
 }

 void ObserveObject::NotifyObserver()
 {
     cout << "  通知被观察者对象\n";
	 //定义两个迭代器
	 list<Observer*>::iterator itr1;
     list<Observer*>::iterator	itr2;
     for (itr1 = ListObserver.begin(), itr2 = ListObserver.end(); itr1 != itr2; ++itr1){
		 //被观察者更新自身状态
         (*itr1)->Update(this);
     }
 }
 
 void ObserveObject::SetSubject(m nState)
 {
	 //设定主体状态
     cout << "   主体状态已修改！\n";
	 SubjectState = nState;
 }
 
 m ObserveObject::ReturnSubjectState()
 {
	 //获取主体的状态
     cout << "   已获得主体状态\n";
     return SubjectState;
 }
 
 ObserveObjesct::~ObserveObject()
 {
	 //定义Observer类型的迭代器
     list<Observer*>::iterator itr1, itr2, Itr;
     //遍历删除所有Observer
     for (itr1 = ListObserver.begin(), itr2 = ListObserver.end();itr1 != itr2;){
		 Itr = itr1;
         ++itr1;
         delete (*Itr);
     }
     //清空原List
     ListObserver.clear();
 }

 void ConcreteObserveObject::SetSubject(m nState)
 {
	 //将继承父类的SetSubject实现
     cout << "   具体观察对象已设定状态！\n";
	 //修改成员变量值
     SubjectState = nState;
 }
 
 m ConcreteObserveObject::ReturnSubjectState()
 {
	 //将继承父类的ReturnSubjectState实现
     cout << "   具体观察对象获取状态！\n";
     return SubjectState;
 }
 
 void ConcreteObserver::Update(ObserveObject* pSubject)
 {
	 //如果传入参数值不对
     if (NULL == pSubject)return; 
	 //获取它的观察者的状态
     ObserverState = pSubject->ReturnSubjectState();
     cout << "    被观察对象的值为 " << ObserverState << endl;
 }
