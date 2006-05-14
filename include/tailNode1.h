// tailNode1.h: interface for the tailNode class.
	//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TAILNODE1_H__AF2DA1AC_0F1A_4980_9241_CFEA2DEBCAF4__INCLUDED_)
#define AFX_TAILNODE1_H__AF2DA1AC_0F1A_4980_9241_CFEA2DEBCAF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "baseNode.h"

template <class T>
class tailNode : public baseNode<T>
{
public:
	tailNode<T>(){};
	~tailNode<T>(){};

	
	virtual void	getIndex(unsigned int count,unsigned int index,baseNode<T>*& node){};
	
	virtual T*&				getValue(){return new T;};
	virtual T*				getValue() const {return new T;};

	baseNode<T>* last;

};

#endif // !defined(AFX_TAILNODE1_H__AF2DA1AC_0F1A_4980_9241_CFEA2DEBCAF4__INCLUDED_)
