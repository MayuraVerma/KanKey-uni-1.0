LIBS = "$(CORESDKLIB)\advapi32.lib" "$(CORESDKLIB)\user32.lib" "$(CORESDKLIB)\ole32.lib" "$(CORESDKLIB)\kernel32.lib" "$(CORESDKLIB)\oleaut32.lib" "$(CORESDKLIB)\uuid.lib" "$(OTHERLIB)\comsupp.lib" "$(OTHERLIB)\libcmt.lib" "$(OTHERLIB)\oldnames.lib"

TestConv.exe: TestConv.obj String.obj
	link /out:TestConv.exe TestConv.obj String.obj $(LIBS)

TestConv.obj: testconv.cpp ctestconv.h cconvprefs.h
	cl /c TestConv.cpp

String.obj: String.cpp _string.h
	cl /c String.cpp
