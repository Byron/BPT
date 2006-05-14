// linkedNode.h: interface for the linkedNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKEDNODE_H__A730C01B_EA7C_4602_BDEB_706BC5D18211__INCLUDED_)
#define AFX_LINKEDNODE_H__A730C01B_EA7C_4602_BDEB_706BC5D18211__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



template <class T>
class linkedNode 
{
public:

	linkedNode():object(0),next(0){};
	linkedNode(T* inObject):object(inObject),next(0){}; //mit dem unteren destruktor wird ein objekt übrigbleiben, mindestens
	~linkedNode(){ /*if(object != 0)delete object;*/ if(next != 0)delete next; };
	//~linkedNode(){cout<<"RUFE LINKED NODE DESTRUKTOR"<<endl;};
	

	void	getIndex( int count, int index,linkedNode<T>*& node);

	

	T*&				getValue(){return object;};
	T*				getValue() const {return object;};

	linkedNode<T>* next;

	

private:
	T* object;

	

};

template <class T>
void	linkedNode<T>::getIndex( int count, int index,linkedNode<T>*& node)
{	

	if(count == index)
		node = this;
	else
		next->getIndex(++count,index,node);

}

#endif // !defined(AFX_LINKEDNODE_H__A730C01B_EA7C_4602_BDEB_706BC5D18211__INCLUDED_)
