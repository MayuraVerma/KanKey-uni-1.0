; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKanKeyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KanKey.h"

ClassCount=4
Class1=CKanKeyApp
Class2=CKanKeyDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_KANKEY_DIALOG

[CLS:CKanKeyApp]
Type=0
HeaderFile=KanKey.h
ImplementationFile=KanKey.cpp
Filter=N

[CLS:CKanKeyDlg]
Type=0
HeaderFile=KanKeyDlg.h
ImplementationFile=KanKeyDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=KanKeyDlg.h
ImplementationFile=KanKeyDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KANKEY_DIALOG]
Type=1
Class=CKanKeyDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

