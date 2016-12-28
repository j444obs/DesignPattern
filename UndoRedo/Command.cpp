#ifndef _COMMAND_CPP  
#define _COMMAND_CPP  
  
#include <iostream>  
#include <stack>  
#include <string>  
#include"Command.h"
using namespace std;
//单步编辑操作类，虚基类
class BaseEdit{  
public:  
	BaseEdit(){}
    virtual ~BaseEdit(){}
    //接口类，在继承后具体实现
    virtual void Execute() = 0;  
};    
class EditInput : public BaseEdit
{  
    public:    
		EditInput( const std::string &input ){  
            mInput = input;  
        }  
        ~EditInput(){}  
		//显示当前的编辑状态Edit
        void Execute(){  
            printf( "  current string: %s\n", mInput.c_str() );  
        }    
	private:    
		std::string mInput;  
};  
//处理编辑状态的Undo/Redo  
class HandleUndoRedo
{  
	public:  
	HandleUndoRedo(BaseEdit *pCmd ){  
        //输入起始的命令数据  
        mUndo.push( pCmd );  
    }  
    ~HandleUndoRedo(){  
        while( false == mUndo.empty() )  {  
            delete mUndo.top();  
            mUndo.pop();  
        }  
        while( false == mRedo.empty() )  {  
            delete mRedo.top();  
            mRedo.pop();  
        }  
    }  
    //添加当前新的编辑状态
    void ExecuteCommand(BaseEdit *pCmd )
    {  
        pCmd->Execute();  
        mUndo.push( pCmd );  
    }  
    //Undo操作
    void Undo()  {  
        if( mUndo.size() < 2 ){  
            //无法后退，撤销没有数据  
            printf( "  undo failed.\n" );  
            return;  
        }  
        printf( "  undo:\n" );   
        //当前命令  
        auto pCmd = mUndo.top();    
        //保存当前命令  
        mRedo.push( pCmd );    
        //弹出  
        mUndo.pop();   
        //还原到上个命令  
        pCmd = mUndo.top();            
        pCmd->Execute();  
    }  
    //Redo操作
    void Redo()  {  
        if( mRedo.empty() )  {  
            //无法前进重做，没有数据  
            printf( "  redo failed.\n" );  
            return;  
        }printf( "  redo:\n" );    
        auto pCmd = mRedo.top();    
        pCmd->Execute();  
        mRedo.pop();  
        mUndo.push( pCmd );  
    }  
  
	private:  
		//使用两个Undo，Redo的栈来实现Undo/Redo
		std::stack< BaseEdit* > mUndo;
		std::stack< BaseEdit* > mRedo;
};  
  
#endif 