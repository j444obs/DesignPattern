#include"Observer.h"
#include<iostream>
using namespace std;
int main(){
	 //�½����ɸ����۲��߶���
		 Observer *OB1 = new ConcreteObserver;
		 Observer *OB2 = new ConcreteObserver;
		 Observer *OB3 = new ConcreteObserver;
		 Observer *OB4 = new ConcreteObserver;
		 Observer *OB5 = new ConcreteObserver;
     //����һ���۲�����ObserveObject����
		 ObserveObject* Observing = new ConcreteObserveObject;
	 //��Observer
		 Observing->AddObserver(OB1);
		 Observing->AddObserver(OB2);
		 Observing->AddObserver(OB3);
		 Observing->AddObserver(OB4);		 
		 Observing->AddObserver(OB5);
		 cout<<endl;

	 /*�ı�۲��ߵ�״̬*/cout<<"  �۲�����״̬�ı�!\n";
	 Observing->SetSubject(123456);				cout<<endl;
	 //NotifyObserver()��������ÿһ�����۲��߶���Ӧ
	 Observing->NotifyObserver();
	 //������
	 cout<<endl;
     //�Ƴ��۲���
	 Observing->RemoveObserver(OB1);
	 //�ٴθı�����״̬
	 Observing->SetSubject(7654321);
	 cout<<endl;
	 Observing->NotifyObserver();
	 //�ͷ��ڴ�
     delete Observing;
	 system("pause");
	 return 0;
}