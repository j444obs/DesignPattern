#ifndef _COMMAND_CPP  
#define _COMMAND_CPP  
  
#include <iostream>  
#include <stack>  
#include <string>  
#include"Command.h"
using namespace std;
//�����༭�����࣬�����
class BaseEdit{  
public:  
	BaseEdit(){}
    virtual ~BaseEdit(){}
    //�ӿ��࣬�ڼ̳к����ʵ��
    virtual void Execute() = 0;  
};    
class EditInput : public BaseEdit
{  
    public:    
		EditInput( const std::string &input ){  
            mInput = input;  
        }  
        ~EditInput(){}  
		//��ʾ��ǰ�ı༭״̬Edit
        void Execute(){  
            printf( "  current string: %s\n", mInput.c_str() );  
        }    
	private:    
		std::string mInput;  
};  
//����༭״̬��Undo/Redo  
class HandleUndoRedo
{  
	public:  
	HandleUndoRedo(BaseEdit *pCmd ){  
        //������ʼ����������  
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
    //��ӵ�ǰ�µı༭״̬
    void ExecuteCommand(BaseEdit *pCmd )
    {  
        pCmd->Execute();  
        mUndo.push( pCmd );  
    }  
    //Undo����
    void Undo()  {  
        if( mUndo.size() < 2 ){  
            //�޷����ˣ�����û������  
            printf( "  undo failed.\n" );  
            return;  
        }  
        printf( "  undo:\n" );   
        //��ǰ����  
        auto pCmd = mUndo.top();    
        //���浱ǰ����  
        mRedo.push( pCmd );    
        //����  
        mUndo.pop();   
        //��ԭ���ϸ�����  
        pCmd = mUndo.top();            
        pCmd->Execute();  
    }  
    //Redo����
    void Redo()  {  
        if( mRedo.empty() )  {  
            //�޷�ǰ��������û������  
            printf( "  redo failed.\n" );  
            return;  
        }printf( "  redo:\n" );    
        auto pCmd = mRedo.top();    
        pCmd->Execute();  
        mRedo.pop();  
        mUndo.push( pCmd );  
    }  
  
	private:  
		//ʹ������Undo��Redo��ջ��ʵ��Undo/Redo
		std::stack< BaseEdit* > mUndo;
		std::stack< BaseEdit* > mRedo;
};  
  
#endif 