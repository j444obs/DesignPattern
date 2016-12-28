// src_Observer.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"Observer.h"
#include <iostream>
#include <algorithm>
using namespace std;
 
 void ObserveObject::RemoveObserver(Observer *pObserver)
 {
	 //����һ��������
     list<Observer*>::iterator iter;
     iter = find(ListObserver.begin(), ListObserver.end(), pObserver);
     //�ҵ�Ҫ�Ƴ��ĵ�����λ��
     if (ListObserver.end() != iter){
		 ListObserver.erase(iter);
     }
     cout << "  �Ƴ��۲����ɹ���\n";
 }
 void ObserveObject::AddObserver(Observer *pObserver)
 {
	 cout << " ��ӹ۲����ɹ���\n";
	 //list������µĹ۲���
	 ListObserver.push_back(pObserver);
 }

 void ObserveObject::NotifyObserver()
 {
     cout << "  ֪ͨ���۲��߶���\n";
	 //��������������
	 list<Observer*>::iterator itr1;
     list<Observer*>::iterator	itr2;
     for (itr1 = ListObserver.begin(), itr2 = ListObserver.end(); itr1 != itr2; ++itr1){
		 //���۲��߸�������״̬
         (*itr1)->Update(this);
     }
 }
 
 void ObserveObject::SetSubject(m nState)
 {
	 //�趨����״̬
     cout << "   ����״̬���޸ģ�\n";
	 SubjectState = nState;
 }
 
 m ObserveObject::ReturnSubjectState()
 {
	 //��ȡ�����״̬
     cout << "   �ѻ������״̬\n";
     return SubjectState;
 }
 
 ObserveObjesct::~ObserveObject()
 {
	 //����Observer���͵ĵ�����
     list<Observer*>::iterator itr1, itr2, Itr;
     //����ɾ������Observer
     for (itr1 = ListObserver.begin(), itr2 = ListObserver.end();itr1 != itr2;){
		 Itr = itr1;
         ++itr1;
         delete (*Itr);
     }
     //���ԭList
     ListObserver.clear();
 }

 void ConcreteObserveObject::SetSubject(m nState)
 {
	 //���̳и����SetSubjectʵ��
     cout << "   ����۲�������趨״̬��\n";
	 //�޸ĳ�Ա����ֵ
     SubjectState = nState;
 }
 
 m ConcreteObserveObject::ReturnSubjectState()
 {
	 //���̳и����ReturnSubjectStateʵ��
     cout << "   ����۲�����ȡ״̬��\n";
     return SubjectState;
 }
 
 void ConcreteObserver::Update(ObserveObject* pSubject)
 {
	 //����������ֵ����
     if (NULL == pSubject)return; 
	 //��ȡ���Ĺ۲��ߵ�״̬
     ObserverState = pSubject->ReturnSubjectState();
     cout << "    ���۲�����ֵΪ " << ObserverState << endl;
 }
