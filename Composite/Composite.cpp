//Composite.h

#include"Composite.h"
#include<iostream>
using namespace std;

Component::~Component() {}
Component::Component(){}


void Component::Remove(Component*com){
	cout<<"  ����Ƴ��ɹ�y!"<<endl;
}
void Component::Add(Component* com) {
	cout << "  �����ӳɹ�!" << endl;
}
void Component::CommonOperation(){
	cout<<"    ��Ԫ������ >>> "<<endl;
}
Component* Component::GetChild(int index){
	return NULL;
}

SingleElement::~SingleElement(){
	//
}

SingleElement::SingleElement() {
	//
}
void SingleElement::CommonOperation(){
	cout<<"      ��Ԫ������ >>>"<<endl;
}

Composite::Composite(){
	//
}
Composite::~Composite(){
	//
}

void Composite::Remove(Component* com) {
	vector<Component*>::iterator itr = this->Child_nodes.begin();
	vector<Component*>::iterator temp_itr = this->Child_nodes.begin();
	while (itr != this->Child_nodes.end()) {
		if (*itr == com)break;
		else itr++;
	}
	temp_itr = itr;
	this->Child_nodes.erase(temp_itr);
	cout << "  ����Ԫ���Ƴ��ɹ�!" << endl;
}
void Composite::Add(Component* com){
	this->Child_nodes.push_back(com);
	cout<<"  �����ӳɹ�!"<<endl;
}

void Composite::CommonOperation(){
	cout<<"    ��Ԫ�ذ������� >>> "<<endl;
	vector<Component*>::iterator iter=this->Child_nodes.begin();
	for(;iter!=this->Child_nodes.end();iter++){
		(*iter)->CommonOperation();
	}
}

Component* Composite::GetChild(int index){
	if(index<0 || index>this->Child_nodes.size()){
		return NULL;
	}
	return this->Child_nodes[index];
}