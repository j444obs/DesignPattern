// src_Composite.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
#include"Composite.h"
using namespace std;

int main(){
	
	//定义一个Component对象同济大学
		Component* Tongji=new Composite();
	//定义同济大学的分学院，软件学院，电信学院，机械学院，材料学院，医学院，并添加进Component对象
		SingleElement* Soft=new SingleElement();
		SingleElement* Telecom=new SingleElement();
		SingleElement* Machine=new SingleElement();
		SingleElement* Material=new SingleElement();
		SingleElement* Medical=new SingleElement();
	//Add操作
		Tongji->Add(Soft);
		Tongji->Add(Telecom);
		Tongji->Add(Machine);
		Tongji->Add(Material);
		Tongji->Add(Medical);cout << "   Tongji\n";
	//显示父元素与子元素之间的包含关系	
	Tongji->CommonOperation();
	for(int i=0;i<5;i++){
		Tongji->GetChild(i);
	}
	cout<<"\t软件学院\n"<<"\t电信学院\n"<<"\t机械学院\n"<<"\t材料学院\n"<<"\t医学院\n";cout<<"   软件学院\n";
	//单个元素节点的CommonOperation()操作
	Soft->CommonOperation();cout<<"   Tongji\n\n";

	//组件再添加子组件，软件学院分为嵌入式，软件工程管理，网络与主机，软件媒体等四个方向的学生
		SingleElement* Embedded=new SingleElement();
		SingleElement* SoftManage=new SingleElement();
		SingleElement* Network=new SingleElement();
		SingleElement* SoftMedia=new SingleElement();
		Soft->Add(Embedded);
		Soft->Add(SoftManage);
		Soft->Add(Network);
		Soft->Add(SoftMedia);
	/*显示包含关系 /**/cout<<"     软件学院\n";cout<<"     该元素包含以下子元素 >>> "<<endl;
		Soft->CommonOperation();
	/*GetChild*/ for(int i=0;i<3;i++){ Soft->CommonOperation();}
		for(int i=0;i<4;i++){
			Soft->GetChild(i);
		}cout<<"\t嵌入式\n"<<"\t软件工程管理\n"<<"\t网络与主机\n"<<"\t软件媒体\n";
	
	//父组件同济删除子组件材料学院
		Tongji->Remove(Material);
	//移除后的组成
		cout<<"\n移除后\n   Google\n";
		Tongji->CommonOperation();
		for(int i=0;i<4;i++){
			Tongji->GetChild(i);
		}
		cout<<"\t软件学院\n"<<"\t电信学院\n"<<"\t机械学院\n"<<"\t医学院\n";

	//子组件软件学院再移除它的子组件网络与主机方向
		Soft->Remove(Network);
	//移除后的组成
		cout<<"\n移除后\n     软件学院\n"; cout<<"     该元素包括以下 >>> "<<endl;for(int i=0;i<2;i++){Soft->CommonOperation();}
		Soft->CommonOperation();
		for(int i=0;i<3;i++){
			Soft->GetChild(i);
		}cout<<"\t嵌入式\n"<<"\t软件工程管理\n"<<"\t软件媒体\n";
	system("pause");
	return 0;
}

