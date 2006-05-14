# Microsoft Developer Studio Project File - Name="Byronimo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=BYRONIMO - WIN32 M45 DEBUG
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Byronimo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Byronimo.mak" CFG="BYRONIMO - WIN32 M45 DEBUG"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Byronimo - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Byronimo - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Byronimo - Win32 M45 DEBUG" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/BPTImport", BAAAAAAA"
# PROP Scc_LocalPath "..\"
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Byronimo - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya5\lib\OpenMaya.lib D:\Grafik\Maya5\lib\OpenMayaAnim.lib D:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "Byronimo - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "E:\Grafik\Maya4.5\include" /I "../" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /D "NT_PLUGIN" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya4.5\lib\Foundation.lib E:\Grafik\Maya4.5\lib\OpenMaya.lib E:\Grafik\Maya4.5\lib\OpenMayaAnim.lib E:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "Byronimo - Win32 M45 DEBUG"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Byronimo___Win32_M45_DEBUG"
# PROP BASE Intermediate_Dir "Byronimo___Win32_M45_DEBUG"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Byronimo___Win32_M45_DEBUG"
# PROP Intermediate_Dir "Byronimo___Win32_M45_DEBUG"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "E:\Grafik\Maya4.5\include" /I "../" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /D "NT_PLUGIN" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "E:\Grafik\Maya4.5\include" /I "../" /D "WIN32" /D "DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BYRONIMO_EXPORTS" /D "NT_PLUGIN" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya4.5\lib\Foundation.lib E:\Grafik\Maya4.5\lib\OpenMaya.lib E:\Grafik\Maya4.5\lib\OpenMayaAnim.lib E:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya4.5\lib\Foundation.lib E:\Grafik\Maya4.5\lib\OpenMaya.lib E:\Grafik\Maya4.5\lib\OpenMayaAnim.lib E:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /debug /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\Byronimo.dll" /implib:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Vcpp6Sources\BPTImport\API_LIBS\Byronimo.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Byronimo - Win32 Release"
# Name "Byronimo - Win32 Debug"
# Name "Byronimo - Win32 M45 DEBUG"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "UI"

# PROP Default_Filter ""
# Begin Group "Manips"

# PROP Default_Filter ""
# Begin Group "ManipClasses"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ManipStructs.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_base.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_baseVars.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_container.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_file.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_geometry.cpp
# End Source File
# Begin Source File

SOURCE=..\MP_threeAxes.cpp
# End Source File
# Begin Source File

SOURCE=..\smartDestruct.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\BPTNodeManip.cpp
# End Source File
# Begin Source File

SOURCE=..\ByronsPolyToolsNodeManip.cpp
# End Source File
# Begin Source File

SOURCE=..\STEManp.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\openGlOverrides.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_autoPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_container.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_defaultDrawRoutines.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_fnAlignment.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_geometry.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_inputDispatcher.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_rectangle.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_textBox.cpp
# End Source File
# Begin Source File

SOURCE=..\UI_textLine.cpp
# End Source File
# End Group
# Begin Group "Manager"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\manager.cpp
# End Source File
# Begin Source File

SOURCE=..\manipManager.cpp
# End Source File
# Begin Source File

SOURCE=..\UIManager.cpp
# End Source File
# End Group
# Begin Group "Globals"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\BCallbackFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\BGlobals.cpp
# End Source File
# Begin Source File

SOURCE=..\BPTGlobalPrequesites.cpp
# End Source File
# End Group
# Begin Group "Helpers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\BPT_BA.cpp
# End Source File
# Begin Source File

SOURCE=..\BPT_Helpers.cpp
# End Source File
# Begin Source File

SOURCE=..\progressBar.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Byronimo - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Byronimo - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Byronimo - Win32 M45 DEBUG"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "UI_header"

# PROP Default_Filter ""
# Begin Group "MANIPS_header"

# PROP Default_Filter ""
# Begin Group "ManipClasses_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ManipStructs.h
# End Source File
# Begin Source File

SOURCE=.\MP_automated.h
# End Source File
# Begin Source File

SOURCE=.\MP_base.h
# End Source File
# Begin Source File

SOURCE=.\MP_baseVars.h
# End Source File
# Begin Source File

SOURCE=.\MP_container.h
# End Source File
# Begin Source File

SOURCE=.\MP_file.h
# End Source File
# Begin Source File

SOURCE=.\MP_geometry.h
# End Source File
# Begin Source File

SOURCE=.\MP_threeAxes.h
# End Source File
# Begin Source File

SOURCE=.\smartDestruct.h
# End Source File
# End Group
# End Group
# Begin Group "UIDefaultDrawings"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UI_defaultDrawBase.h
# End Source File
# Begin Source File

SOURCE=.\UI_defaultDrawBox.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\openGlOverrides.h
# End Source File
# Begin Source File

SOURCE=.\UI_automated.h
# End Source File
# Begin Source File

SOURCE=.\UI_autoPosition.h
# End Source File
# Begin Source File

SOURCE=.\UI_base.h
# End Source File
# Begin Source File

SOURCE=.\UI_baseVars.h
# End Source File
# Begin Source File

SOURCE=.\UI_container.h
# End Source File
# Begin Source File

SOURCE=.\UI_dispatcher.h
# End Source File
# Begin Source File

SOURCE=.\UI_fnAlignment.h
# End Source File
# Begin Source File

SOURCE=.\UI_geometry.h
# End Source File
# Begin Source File

SOURCE=.\UI_inputDispatcher.h
# End Source File
# Begin Source File

SOURCE=.\UI_rectangle.h
# End Source File
# Begin Source File

SOURCE=.\UI_textBox.h
# End Source File
# Begin Source File

SOURCE=.\UI_textLine.h
# End Source File
# End Group
# Begin Group "MANAGER_Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\manager.h
# End Source File
# Begin Source File

SOURCE=..\manipManager.h
# End Source File
# Begin Source File

SOURCE=..\UIManager.h
# End Source File
# End Group
# Begin Group "Helpers_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\BPT_BA.h
# End Source File
# Begin Source File

SOURCE=..\BPT_Helpers.h
# End Source File
# Begin Source File

SOURCE=..\progressBar.h
# End Source File
# End Group
# Begin Group "Globals_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\BCallback.h
# End Source File
# Begin Source File

SOURCE=..\BCallbackFunctions.h
# End Source File
# Begin Source File

SOURCE=..\BGlobals.h
# End Source File
# Begin Source File

SOURCE=..\BPTGlobalPrequesites.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\MACROS.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
