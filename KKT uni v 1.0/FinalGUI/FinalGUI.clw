; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Menu_Cust
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FinalGUI.h"

ClassCount=8
Class1=CFinalGUIApp
Class2=CFinalGUIDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FINALGUI_DIALOG
Class4=Language
Resource4=IDD_DIALOG4
Class5=Layout
Resource5=IDD_DIALOG2
Resource6=IDD_KEYBOARD
Class6=About
Class7=Help
Resource7=IDD_DIALOG3
Resource8=IDD_CUST_MENU
Class8=Menu_Cust
Resource9=IDR_MENU1

[CLS:CFinalGUIApp]
Type=0
HeaderFile=FinalGUI.h
ImplementationFile=FinalGUI.cpp
Filter=N

[CLS:CFinalGUIDlg]
Type=0
HeaderFile=FinalGUIDlg.h
ImplementationFile=FinalGUIDlg.cpp
Filter=D
LastObject=CFinalGUIDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FinalGUIDlg.h
ImplementationFile=FinalGUIDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDOK,button,1342373889
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_FINALGUI_DIALOG]
Type=1
Class=CFinalGUIDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

[CLS:Language]
Type=0
HeaderFile=Language.h
ImplementationFile=Language.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO1

[DLG:IDD_DIALOG2]
Type=1
Class=Layout
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_RADIO1,button,1342308361
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_RADIO4,button,1342177289

[CLS:Layout]
Type=0
HeaderFile=Layout.h
ImplementationFile=Layout.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=Help
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG4]
Type=1
Class=About
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287

[CLS:About]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=About

[CLS:Help]
Type=0
HeaderFile=Help.h
ImplementationFile=Help.cpp
BaseClass=CDialog
Filter=D

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_TRAYMENU_ITEM1
Command2=ID_TRAYMENU_ITEM2
Command3=ID_TRAYMENU_ITEM3
CommandCount=3

[DLG:IDD_CUST_MENU]
Type=1
Class=Menu_Cust
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344340227

[CLS:Menu_Cust]
Type=0
HeaderFile=Menu_Cust.h
ImplementationFile=Menu_Cust.cpp
BaseClass=CDialog
Filter=D
LastObject=Menu_Cust
VirtualFilter=dWC

[DLG:IDD_KEYBOARD]
Type=1
Class=Language
ControlCount=3
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342312457
Control3=IDC_RADIO2,button,1342181385

