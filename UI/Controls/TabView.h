//===========
// TabView.h
//===========

#pragma once


//=======
// Using
//=======

#include "Collections/Map.h"
#include "Control.h"


//===========
// Namespace
//===========

namespace UI {
	namespace Controls {


//==========
// Tab-View
//==========

class TabView: public Control
{
public:
	// Tab-Info
	class TabInfo: public Object
		{
		public:
			// Common
			Handle<String> Title;
		};

	// Con-/Destructors
	static inline Handle<TabView> Create(Window* Parent) { return new TabView(Parent); }

	// Common
	Handle<TabInfo> AddTab(Window* Tab);
	VOID RemoveTab(Window* Tab);

private:
	// Using
	using TabMap=Collections::Map<Window*, Handle<TabInfo>>;

	// Con-/Destructors
	TabView(Window* Parent);

	// Common
	Handle<TabMap> m_Tabs;
};

}}