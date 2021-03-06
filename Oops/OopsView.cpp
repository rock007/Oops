
// OopsView.cpp : implementation of the COopsView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Oops.h"
#endif

#include "OopsDoc.h"
#include "OopsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COopsView

IMPLEMENT_DYNCREATE(COopsView, CView)

BEGIN_MESSAGE_MAP(COopsView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// COopsView construction/destruction

COopsView::COopsView()
{
	// TODO: add construction code here

}

COopsView::~COopsView()
{
}

BOOL COopsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COopsView drawing

void COopsView::OnDraw(CDC* /*pDC*/)
{
	COopsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void COopsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COopsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COopsView diagnostics

#ifdef _DEBUG
void COopsView::AssertValid() const
{
	CView::AssertValid();
}

void COopsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COopsDoc* COopsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COopsDoc)));
	return (COopsDoc*)m_pDocument;
}
#endif //_DEBUG


// COopsView message handlers
