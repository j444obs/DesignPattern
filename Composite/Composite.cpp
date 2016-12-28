//Composite.h

#include"Composite.h"
#include<iostream>
using namespace std;

Component::~Component() {}
Component::Component(){}


void Component::Remove(Component*com){
	cout<<"  组件移除成功y!"<<endl;
}
void Component::Add(Component* com) {
	cout << "  组件添加成功!" << endl;
}
void Component::CommonOperation(){
	cout<<"    该元素属于 >>> "<<endl;
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
	cout<<"      该元素属于 >>>"<<endl;
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
	cout << "  复合元素移除成功!" << endl;
}
void Composite::Add(Component* com){
	this->Child_nodes.push_back(com);
	cout<<"  组件添加成功!"<<endl;
}

void Composite::CommonOperation(){
	cout<<"    该元素包括以下 >>> "<<endl;
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