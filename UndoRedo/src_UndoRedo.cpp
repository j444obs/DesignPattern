// src_UndoRedo.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include "Command.cpp"  
  
using namespace std;
//使用命令行的输入模拟输入字符串,然后对输入的字符串进行undo redo操作，如果在undo 或 redo 过程中又发生数据改变也会记录,如果不想这样在undo 或者 redo 输入新字符串时，将redo清空即可，即认为在历史记录中修改值被认为是最新的值，不需要再redo  
int main()  
{  
    //输入起始的空状态时的编辑状态 
	HandleUndoRedo *p = new HandleUndoRedo( new EditInput( "  【Start Condition】\n" ) );  
    //输入四条编辑的历史状态 
		p->ExecuteCommand( new EditInput( "    1.ABCDEFG\n" ) );
		p->ExecuteCommand( new EditInput( "  2.QWERTYU\n" ) );  
		p->ExecuteCommand( new EditInput( "  3.ASDFGHJ\n" ) ); 
		p->ExecuteCommand( new EditInput( "  4.ZXCVBNM\n" ) );  
		p->ExecuteCommand( new EditInput( "  5.SDFGHJK\n" ) );  
    //执行一次undo 撤销
		p->Undo();  
    //再执行一次undo 撤销
		p->Undo();  
	//再执行一次undo 撤销
		p->Undo();     
    //执行一次undo 撤销到第一句
		p->Undo();    
    //执行一次undo 撤销到最初情况 【起始状态】  
		p->Undo();    
    //执行失败，因为已经undo 到最原始情况，不能再 Redo() 
		p->Undo();cout<<endl;  
  
    //一次redo 重做到开头 
		p->Redo();  
    //执行一次redo 重做到第一句  
		p->Redo();  
    //一次redo 重做到第二句
	  p->Redo(); 
	//一次redo 重做到第三句
		p->Redo();  
	
	cout<<"   添加新的Undo和Redo记录\n";
    //输入新字符串 “  QAZWSX” 覆盖当前字符串  
    p->ExecuteCommand( new EditInput( "  New.QAZWSX\n" ) );
    //执行一次undo 
    p->Undo();    
    //一次redo 重做
    p->Redo();    
    //执行一次redo 重做
    p->Redo();    
    // Redo执行失败，已经到最新情况  
    p->Redo();  
	cout<<endl;
	//释放HandleUndoRedo对象内存
    delete p;  
	system("pause");
    return 0;  
}  

