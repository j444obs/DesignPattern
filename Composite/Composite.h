#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
#include <vector> 
using namespace std;

class Component{
public:
     virtual void CommonOperation()=0;    
     virtual void Add(Component*);
     virtual void Remove(Component*);
     virtual Component* GetChild(int index);
     virtual ~Component();
protected:
     Component();
};
 
/*����Ԫ�ؽڵ�,��������������Ľ���࣬���Բ���ʵ��Add��Remove��GetChild�ȷ��� */
class SingleElement:public Component{
public:
     //ֻʵ�ֹ����ӿ�
     virtual void CommonOperation();
	 SingleElement();
     ~SingleElement();
}; 
 class Composite:public Component{
 public:
     Composite();
     ~Composite();
     //ʵ�����нӿ�
     void CommonOperation();
     void Add(Component*);
     void Remove(Component*);
     Component* GetChild(int index);
 private:
     //��vector�����������
     vector<Component*> Child_nodes;        
 };
 #endif