// src_Composite.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include<iostream>
#include"Composite.h"
using namespace std;

int main(){
	
	//����һ��Component����ͬ�ô�ѧ
		Component* Tongji=new Composite();
	//����ͬ�ô�ѧ�ķ�ѧԺ�����ѧԺ������ѧԺ����еѧԺ������ѧԺ��ҽѧԺ������ӽ�Component����
		SingleElement* Soft=new SingleElement();
		SingleElement* Telecom=new SingleElement();
		SingleElement* Machine=new SingleElement();
		SingleElement* Material=new SingleElement();
		SingleElement* Medical=new SingleElement();
	//Add����
		Tongji->Add(Soft);
		Tongji->Add(Telecom);
		Tongji->Add(Machine);
		Tongji->Add(Material);
		Tongji->Add(Medical);cout << "   Tongji\n";
	//��ʾ��Ԫ������Ԫ��֮��İ�����ϵ	
	Tongji->CommonOperation();
	for(int i=0;i<5;i++){
		Tongji->GetChild(i);
	}
	cout<<"\t���ѧԺ\n"<<"\t����ѧԺ\n"<<"\t��еѧԺ\n"<<"\t����ѧԺ\n"<<"\tҽѧԺ\n";cout<<"   ���ѧԺ\n";
	//����Ԫ�ؽڵ��CommonOperation()����
	Soft->CommonOperation();cout<<"   Tongji\n\n";

	//������������������ѧԺ��ΪǶ��ʽ��������̹������������������ý����ĸ������ѧ��
		SingleElement* Embedded=new SingleElement();
		SingleElement* SoftManage=new SingleElement();
		SingleElement* Network=new SingleElement();
		SingleElement* SoftMedia=new SingleElement();
		Soft->Add(Embedded);
		Soft->Add(SoftManage);
		Soft->Add(Network);
		Soft->Add(SoftMedia);
	/*��ʾ������ϵ /**/cout<<"     ���ѧԺ\n";cout<<"     ��Ԫ�ذ���������Ԫ�� >>> "<<endl;
		Soft->CommonOperation();
	/*GetChild*/ for(int i=0;i<3;i++){ Soft->CommonOperation();}
		for(int i=0;i<4;i++){
			Soft->GetChild(i);
		}cout<<"\tǶ��ʽ\n"<<"\t������̹���\n"<<"\t����������\n"<<"\t���ý��\n";
	
	//�����ͬ��ɾ�����������ѧԺ
		Tongji->Remove(Material);
	//�Ƴ�������
		cout<<"\n�Ƴ���\n   Google\n";
		Tongji->CommonOperation();
		for(int i=0;i<4;i++){
			Tongji->GetChild(i);
		}
		cout<<"\t���ѧԺ\n"<<"\t����ѧԺ\n"<<"\t��еѧԺ\n"<<"\tҽѧԺ\n";

	//��������ѧԺ���Ƴ������������������������
		Soft->Remove(Network);
	//�Ƴ�������
		cout<<"\n�Ƴ���\n     ���ѧԺ\n"; cout<<"     ��Ԫ�ذ������� >>> "<<endl;for(int i=0;i<2;i++){Soft->CommonOperation();}
		Soft->CommonOperation();
		for(int i=0;i<3;i++){
			Soft->GetChild(i);
		}cout<<"\tǶ��ʽ\n"<<"\t������̹���\n"<<"\t���ý��\n";
	system("pause");
	return 0;
}

