#pragma once
//#include <string>
#include "RenderObject.h"

struct InvPos
{
	std::pair<int, int> pos = std::make_pair(0,0);
	bool gridPosFilled = false;
};

class Item
{
public:
	Item() {}
	Item(std::string name, int cost);
	~Item();
	std::string GetName() const;
	std::string GetObjName() const;
	int GetCost() const;
	RenderObject* GetRenderObject();
	void SetObjName(std::string name);
	void SetRenderObject(RenderObject* obj);

	void OnHover();
	void OnLeave();
	bool bPickedUp = false;
	InvPos inventoryPos;
protected:
	std::string mName;
	std::string mObjName;
private:
	RenderObject* mRenderObject;
	int mCost;
	
	
	
	
};

