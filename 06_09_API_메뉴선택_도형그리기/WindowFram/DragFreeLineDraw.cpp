#include "DragFreeLineDrawing.h"
CDragFreeLineDrawing* CDragFreeLineDrawing::mPthis = nullptr;

void CDragFreeLineDrawing::Create()
{
	if (!mPthis)
	{
		mPthis = new CDragFreeLineDrawing();
	}

}
CDragFreeLineDrawing* CDragFreeLineDrawing::GetInstance()
{
	return mPthis;
}
void CDragFreeLineDrawing::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDragFreeLineDrawing::DragDrawing(CBackBit* _bit, COLORREF bColor, COLORREF pColor, int PenPt, int _drawmode)
{
	CMouse* mouse = CMouse::GetInstance();

	if (mouse->GetClick())
	{

		HDC hdc = _bit->GetBitmapDC();
		HPEN hPen = CreatePen(PS_SOLID, PenPt, pColor);
		HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
		MoveToEx(hdc, mouse->GetOldX(), mouse->GetOldy(), NULL);
		LineTo(hdc, mouse->GetX(), mouse->Gety());
		DeleteObject(SelectObject(hdc, hOldPen));
		_bit->DeleteBitmapDC(hdc);
		InvalidateRect(mouse->GetHWnd(), NULL, false);
	}

}