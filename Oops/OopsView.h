
// OopsView.h : interface of the COopsView class
//

#pragma once


class COopsView : public CView
{
protected: // create from serialization only
	COopsView();
	DECLARE_DYNCREATE(COopsView)

// Attributes
public:
	COopsDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~COopsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OopsView.cpp
inline COopsDoc* COopsView::GetDocument() const
   { return reinterpret_cast<COopsDoc*>(m_pDocument); }
#endif

