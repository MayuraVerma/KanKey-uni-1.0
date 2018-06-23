#include "windows.h"
#include "_string.h"

void CopyWz(const WCHAR *wzSource, WCHAR *wzDest, int ichMax)
{
	int ich = 0;

	if (ichMax < 0 || wzSource == NULL || wzDest == NULL)
		return;

	while (wzSource[ich] != 0)
		{
		if (ich >= ichMax)
			break;
		wzDest[ich] = wzSource[ich];
		ich++;
		}

	wzDest[ich] = 0;
}

void CopyBstrToWz(BSTR bstrSource, WCHAR *wzDest, unsigned int ichMax)
{
	unsigned int cchSource = SysStringLen(bstrSource);
	unsigned int ichCopy = 0;

	if (bstrSource != NULL && cchSource != 0)
		{
		ichCopy = cchSource + 1;
		if (ichCopy > ichMax)
			ichCopy = ichMax;
		CopyWz(bstrSource, wzDest, ichCopy - 1);
		}

	wzDest[ichCopy] = 0;
}


void AppendWz(const WCHAR *wzSrc, WCHAR *wzDest, int ichMax)
{
	WCHAR *wz;

	if (wzSrc == NULL || wzDest == NULL)
		return;

	wz = wzDest + wcslen(wzDest);
	CopyWz(wzSrc, wz, ichMax - wcslen(wzDest));
}


void IToW(int i, WCHAR *wzDest, int ichMax)
{
	_itow_s(i, wzDest, ichMax, 10 /*radix*/);
}


bool FEqWz(const WCHAR *wz1, const WCHAR *wz2)
{
	return (wcscmp(wz1, wz2) == 0);
}
