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
 
/*单个元素节点,即不含有子组件的结点类，所以不用实现Add、Remove、GetChild等方法 */
class SingleElement:public Component{
public:
     //只实现公共接口
     virtual void CommonOperation();
	 SingleElement();
     ~SingleElement();
}; 
 class Composite:public Component{
 public:
     Composite();
     ~Composite();
     //实现所有接口
     void CommonOperation();
     void Add(Component*);
     void Remove(Component*);
     Component* GetChild(int index);
 private:
     //用vector来保存子组件
     vector<Component*> Child_nodes;        
 };
 #endif