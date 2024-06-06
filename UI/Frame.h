//=========
// Frame.h
//=========

#pragma once


//=======
// Using
//=======

#include "Collections/Map.h"
#include "Graphics/RenderTarget.h"
#include "UI/Controls/Menus/Menu.h"
#include "UI/Controls/Interactive.h"
#include "Window.h"


//===========
// Namespace
//===========

namespace UI {


//=======
// Frame
//=======

class Frame: public Window
{
public:
	// Using
	using Cursor=Graphics::Cursor;
	using FocusReason=UI::Controls::FocusReason;
	using Interactive=UI::Controls::Interactive;
	using KeyEventType=UI::Input::KeyEventType;
	using KeyEventArgs=UI::Input::KeyEventArgs;
	using Menu=UI::Controls::Menus::Menu;
	using POINT=Graphics::POINT;
	using PointerButton=UI::Input::PointerButton;
	using PointerEventArgs=UI::Input::PointerEventArgs;
	using PointerEventType=UI::Input::PointerEventType;
	using RECT=Graphics::RECT;
	using RenderTarget=Graphics::RenderTarget;
	using ShortcutMap=Collections::Map<UINT, Interactive*>;
	using VirtualKey=UI::Input::VirtualKey;

	// Con-/Destructors
	Frame();

	// Common
	static Frame* Current;
	Interactive* GetFocus()const { return pFocus; }
	Frame* GetFrame()override { return this; }
	Interactive* GetOldFocus()const { return pOldFocus; }
	Interactive* GetPointerFocus()const { return pPointerFocus; }
	Menu* GetCurrentMenu()const { return pCurrentMenu; }
	SIZE GetMinSize(RenderTarget* Target)override;
	Interactive* GetPointerCapture()const { return pPointerCapture; }
	VOID Invalidate(BOOL Rearrange=false)override;
	Event<Frame> Invalidated;
	BOOL IsKeyDown(VirtualKey Key);
	Event<Frame, KeyEventType, Handle<KeyEventArgs>> KeyEvent;
	VOID KillFocus();
	Event<Frame> PointerCaptured;
	Event<Frame> PointerReleased;
	VOID Rearrange(RenderTarget* Target, RECT& Rect)override;
	VOID SetCurrentMenu(Menu* Menu);
	virtual VOID SetCursor(Handle<Cursor> Cursor) {}
	VOID SetFocus(Interactive* Focus, FocusReason Reason=FocusReason::None);
	virtual VOID SetPointerCapture(Interactive* Capture) { pPointerCapture=Capture; }
	VOID SetPointerFocus(Interactive* Focus);
	Handle<ShortcutMap> Shortcuts;

	// Edit
	VOID EditCopy();
	VOID EditCut();
	VOID EditDelete();
	VOID EditPaste();
	VOID EditSelectAll();

protected:
	// Common
	BOOL DoKey(KeyEventType Type, Handle<KeyEventArgs> Args);
	VOID DoPointer(PointerEventType Type, Handle<PointerEventArgs> Args);
	VOID RenderWindow(Window* Window, RenderTarget* Target, RECT const& Rect, BOOL Override);
	Interactive* pPointerCapture;

private:
	// Common
	BOOL DoMenuPointer(PointerEventType Type, Handle<PointerEventArgs> Args, Interactive** Focus);
	VOID DoPointer(Interactive* Control, PointerEventType Type, Handle<PointerEventArgs> Args);
	BOOL DoPointer(Window* Window, PointerEventType Type, Handle<PointerEventArgs> Args, Interactive** Focus);
	BOOL DoShortcut(KeyEventType Type, Handle<KeyEventArgs> Args);
	VOID ExitMenu();
	VOID UpdateKeys(KeyEventType Type, VirtualKey Key);
	VOID UpdateKeys(PointerEventType Type, PointerButton Button);
	Menu* pCurrentMenu;
	Interactive* pFocus;
	BYTE pKeys[256];
	Interactive* pOldFocus;
	Interactive* pPointerFocus;
};

}
