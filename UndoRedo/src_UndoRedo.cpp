// src_UndoRedo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>
#include "Command.cpp"  
  
using namespace std;
//ʹ�������е�����ģ�������ַ���,Ȼ���������ַ�������undo redo�����������undo �� redo �������ַ������ݸı�Ҳ���¼,�������������undo ���� redo �������ַ���ʱ����redo��ռ��ɣ�����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo  
int main()  
{  
    //������ʼ�Ŀ�״̬ʱ�ı༭״̬ 
	HandleUndoRedo *p = new HandleUndoRedo( new EditInput( "  ��Start Condition��\n" ) );  
    //���������༭����ʷ״̬ 
		p->ExecuteCommand( new EditInput( "    1.ABCDEFG\n" ) );
		p->ExecuteCommand( new EditInput( "  2.QWERTYU\n" ) );  
		p->ExecuteCommand( new EditInput( "  3.ASDFGHJ\n" ) ); 
		p->ExecuteCommand( new EditInput( "  4.ZXCVBNM\n" ) );  
		p->ExecuteCommand( new EditInput( "  5.SDFGHJK\n" ) );  
    //ִ��һ��undo ����
		p->Undo();  
    //��ִ��һ��undo ����
		p->Undo();  
	//��ִ��һ��undo ����
		p->Undo();     
    //ִ��һ��undo ��������һ��
		p->Undo();    
    //ִ��һ��undo ������������ ����ʼ״̬��  
		p->Undo();    
    //ִ��ʧ�ܣ���Ϊ�Ѿ�undo ����ԭʼ����������� Redo() 
		p->Undo();cout<<endl;  
  
    //һ��redo ��������ͷ 
		p->Redo();  
    //ִ��һ��redo ��������һ��  
		p->Redo();  
    //һ��redo �������ڶ���
	  p->Redo(); 
	//һ��redo ������������
		p->Redo();  
	
	cout<<"   ����µ�Undo��Redo��¼\n";
    //�������ַ��� ��  QAZWSX�� ���ǵ�ǰ�ַ���  
    p->ExecuteCommand( new EditInput( "  New.QAZWSX\n" ) );
    //ִ��һ��undo 
    p->Undo();    
    //һ��redo ����
    p->Redo();    
    //ִ��һ��redo ����
    p->Redo();    
    // Redoִ��ʧ�ܣ��Ѿ����������  
    p->Redo();  
	cout<<endl;
	//�ͷ�HandleUndoRedo�����ڴ�
    delete p;  
	system("pause");
    return 0;  
}  

