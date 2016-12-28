#ifndef OBSERVER_H
#define OBSERVER_H 
#include <list>

//������¼��������״̬
typedef int m; 
class Observer;
 
 //�۲�Ķ������ﶨ��Ϊһ�������
 class ObserveObject
 { public:
	 ObserveObject() : SubjectState(-1){}
     virtual ~ObserveObject();
	 //֪ͨ���۲��߶���
     void NotifyObserver();                            
	 //��ӹ۲���
     void AddObserver(Observer *pObserver);         
	 //ɾ���۲���
     void RemoveObserver(Observer *pObserver);         
 
     // �麯��,�����������麯����һ�����趨����״̬
	 //�ı���������״̬
     virtual void   SetSubject(m nState);
	 //����������״̬
     virtual m  ReturnSubjectState();
 
 protected:
	 //�������״̬
	 m SubjectState;
	 //����Observer���۲�����list
     std::list<Observer*>ListObserver;  
 };
 
 //���۲�Ķ���
 class Observer
 {
 public:
     Observer() : ObserverState(-1){}
     virtual ~Observer(){}  
     // update����֪ͨObserver״̬�����˱仯�����麯��,��������������в�ͬ��ʵ��
     virtual void Update(ObserveObject* pSubject) = 0;
 
 protected:
	 //�۲��ߵ�״̬
	 m ObserverState;                    
 };
 
 // �̳�ObserveObject������ʵ�ֹ۲��ߵ�ĳЩ��Ա����
 class ConcreteObserveObject
     : public ObserveObject
 {
 public:
	 ConcreteObserveObject() : ObserveObject(){}
     virtual ~ConcreteObserveObject(){} 
     //ʵ�ָ�����麯��
     virtual void    SetSubject(m nState);    // ����״̬
     virtual m   ReturnSubjectState();                // �õ�״̬
 
 };
 
 // ConcreteObserver��������Observer
 class ConcreteObserver
     : public Observer
 {
 public:
     ConcreteObserver() : Observer(){}
     virtual ~ConcreteObserver(){} 
     // update������֪ͨObserver����������״̬
     virtual void Update(ObserveObject* pSubject);
 };
 
 #endif