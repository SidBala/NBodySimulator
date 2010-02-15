#pragma once

class CMouseHandler
{
public:
	bool m_MouseDown;
	bool m_OldMouseDown;
	bool m_MouseUp;

	CPoint m_CurrentPos;
	CPoint m_DragBegin;
	
public:
	CMouseHandler(void);
	~CMouseHandler(void);
};
