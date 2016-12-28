#include"Observer.h"
#include<iostream>
using namespace std;
int main(){
	 //新建若干个被观察者对象
		 Observer *OB1 = new ConcreteObserver;
		 Observer *OB2 = new ConcreteObserver;
		 Observer *OB3 = new ConcreteObserver;
		 Observer *OB4 = new ConcreteObserver;
		 Observer *OB5 = new ConcreteObserver;
     //创建一个观察主体ObserveObject对象
		 ObserveObject* Observing = new ConcreteObserveObject;
	 //绑定Observer
		 Observing->AddObserver(OB1);
		 Observing->AddObserver(OB2);
		 Observing->AddObserver(OB3);
		 Observing->AddObserver(OB4);		 
		 Observing->AddObserver(OB5);
		 cout<<endl;

	 /*改变观察者的状态*/cout<<"  观察主题状态改变!\n";
	 Observing->SetSubject(123456);				cout<<endl;
	 //NotifyObserver()操作，让每一个被观察者都响应
	 Observing->NotifyObserver();
	 //输出结果
	 cout<<endl;
     //移除观察器
	 Observing->RemoveObserver(OB1);
	 //再次改变主体状态
	 Observing->SetSubject(7654321);
	 cout<<endl;
	 Observing->NotifyObserver();
	 //释放内存
     delete Observing;
	 system("pause");
	 return 0;
}