#pragma once

#include "windows.h"
#include "stdlib.h"
#include "strsafe.h"
#include "oleauto.h"

#define cElements(ary)   (sizeof(ary) / sizeof(ary[0]))

void CopyWz(const WCHAR *wzSource, WCHAR *wzDest, int ichMax);
void CopyBstrToWz(BSTR bstrSource, WCHAR *wzDest, unsigned int ichMax);
void AppendWz(const WCHAR *wzSrc, WCHAR *wzDest, int ichMax);
void IToW(int i, WCHAR *wzDest, int ichMax);
bool FEqWz(const WCHAR *wz1, const WCHAR *wz2);
