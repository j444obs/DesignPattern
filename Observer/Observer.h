#ifndef OBSERVER_H
#define OBSERVER_H 
#include <list>

//用来记录主体对象的状态
typedef int m; 
class Observer;
 
 //观察的对象，这里定义为一个虚基类
 class ObserveObject
 { public:
	 ObserveObject() : SubjectState(-1){}
     virtual ~ObserveObject();
	 //通知被观察者对象
     void NotifyObserver();                            
	 //添加观察器
     void AddObserver(Observer *pObserver);         
	 //删除观察器
     void RemoveObserver(Observer *pObserver);         
 
     // 虚函数,定义了两个虚函数，一个是设定主体状态
	 //改变主体对象的状态
     virtual void   SetSubject(m nState);
	 //获得主体对象状态
     virtual m  ReturnSubjectState();
 
 protected:
	 //主体对象状态
	 m SubjectState;
	 //保存Observer被观察对象的list
     std::list<Observer*>ListObserver;  
 };
 
 //被观察的对象
 class Observer
 {
 public:
     Observer() : ObserverState(-1){}
     virtual ~Observer(){}  
     // update函数通知Observer状态发生了变化，纯虚函数,各个派生类可能有不同的实现
     virtual void Update(ObserveObject* pSubject) = 0;
 
 protected:
	 //观察者的状态
	 m ObserverState;                    
 };
 
 // 继承ObserveObject，具体实现观察者的某些成员函数
 class ConcreteObserveObject
     : public ObserveObject
 {
 public:
	 ConcreteObserveObject() : ObserveObject(){}
     virtual ~ConcreteObserveObject(){} 
     //实现父类的虚函数
     virtual void    SetSubject(m nState);    // 设置状态
     virtual m   ReturnSubjectState();                // 得到状态
 
 };
 
 // ConcreteObserver类派生自Observer
 class ConcreteObserver
     : public Observer
 {
 public:
     ConcreteObserver() : Observer(){}
     virtual ~ConcreteObserver(){} 
     // update函数，通知Observer来更新自身状态
     virtual void Update(ObserveObject* pSubject);
 };
 
 #endif