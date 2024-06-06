//==============
// EditMenu.cpp
//==============

#include "pch.h"


//=======
// Using
//=======

#include "Resources/Icons/Edit.h"
#include "Resources/Strings/Edit.h"
#include "UI/Frame.h"
#include "EditMenu.h"

using namespace Graphics;
using namespace Resources::Icons;
using namespace Resources::Strings;


//===========
// Namespace
//===========

namespace UI {
	namespace Controls {
		namespace Menus {


//==================
// Con-/Destructors
//==================

EditMenu::EditMenu(Frame* frame):
PopupMenu(frame, nullptr)
{
SelectAll=Add(STR_MM_EDIT_SELECT_ALL);
SelectAll->Clicked.Add(frame, &Frame::EditSelectAll);
SelectAll->Icon=new Icon(ICO_EDIT_SELECT_ALL);
Add(nullptr);
Copy=Add(STR_MM_EDIT_COPY);
Copy->Clicked.Add(frame, &Frame::EditCopy);
Copy->Icon=new Icon(ICO_EDIT_COPY);
Add(nullptr);
Cut=Add(STR_MM_EDIT_CUT);
Cut->Clicked.Add(frame, &Frame::EditCut);
Cut->Icon=new Icon(ICO_EDIT_CUT);
Delete=Add(STR_MM_EDIT_DELETE);
Delete->Clicked.Add(frame, &Frame::EditDelete);
Delete->Icon=new Icon(ICO_EDIT_DELETE);
Add(nullptr);
Paste=Add(STR_MM_EDIT_PASTE);
Paste->Clicked.Add(frame, &Frame::EditPaste);
Paste->Icon=new Icon(ICO_EDIT_PASTE);
}

}}}
