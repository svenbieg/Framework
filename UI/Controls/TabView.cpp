//=============
// TabView.cpp
//=============

#include "pch.h"


//=======
// Using
//=======

#include "TabView.h"


//===========
// Namespace
//===========

namespace UI {
	namespace Controls {


//========
// Common
//========

Handle<TabView::TabInfo> TabView::AddTab(Window* tab)
{
tab->Parent=this;
auto tab_info=new TabInfo();
m_Tabs->Add(tab, tab_info);
return tab_info;
}

VOID TabView::RemoveTab(Window* tab)
{
tab->Parent=nullptr;
m_Tabs->Remove(tab);
}


//==========================
// Con-/Destructors Private
//==========================

TabView::TabView(Window* parent):
Control(parent)
{
m_Tabs=TabMap::Create();
}

}}