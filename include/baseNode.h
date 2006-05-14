// baseNode.h: interface for the baseNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASENODE_H__32B186FA_5310_4A64_B613_9BE3ECB0FC2A__INCLUDED_)
#define AFX_BASENODE_H__32B186FA_5310_4A64_B613_9BE3ECB0FC2A__INCLUDED_


template <class T>
class baseNode  
{
public:
	baseNode(){};
	virtual ~baseNode(){};

	
	virtual void	getIndex(unsigned int count,unsigned int index,baseNode<T>*& node) = 0;

	virtual T*&				getValue() = 0;
	virtual T*				getValue() const = 0;

	

};

#endif // !defined(AFX_BASENODE_H__32B186FA_5310_4A64_B613_9BE3ECB0FC2A__INCLUDED_)
