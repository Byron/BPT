# Microsoft Developer Studio Project File - Name="BPTImport" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=BPTImport - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BPTImport.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BPTImport.mak" CFG="BPTImport - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BPTImport - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Release_45" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Release_45_DEBUG" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Release_5" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Release_5_DEBUG" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BPTImport - Win32 Release_6" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Perforce Project"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BPTImport - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BPTIMPORT_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "D:\Grafik\Maya5\include" /D "NDEBUG" /D "NT_PLUGIN" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya5\lib\Foundation.lib D:\Grafik\Maya5\lib\OpenMaya.lib D:\Grafik\Maya5\lib\OpenMayaAnim.lib D:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"D:\ANWENDUNGEN\VisualCpp6\MSDev98\MyProjects\testMayaPlug\Release\ByronsPolyToolsMaya5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BPTIMPORT_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "BPTIMPORT_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"Debug/Byronimo.dll" /pdbtype:sept

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_45"
# PROP BASE Intermediate_Dir "Release_45"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_45"
# PROP Intermediate_Dir "Release_45"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "D:\Grafik\Maya5\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NT_PLUGIN" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "E:\Grafik\Maya4.5\include" /I "./" /D "NDEBUG" /D "NT_PLUGIN" /D "TIMER" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /YX"BPTStableHeaders.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya5\lib\Foundation.lib D:\Grafik\Maya5\lib\OpenMaya.lib D:\Grafik\Maya5\lib\OpenMayaAnim.lib D:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"D:\ANWENDUNGEN\VisualCpp6\MSDev98\MyProjects\testMayaPlug\Release\ByronsPolyToolsMaya5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 ./API_LIBS/Byronimo.lib Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya4.5\lib\Foundation.lib E:\Grafik\Maya4.5\lib\OpenMaya.lib E:\Grafik\Maya4.5\lib\OpenMayaAnim.lib E:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyTools.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45_DEBUG"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BPTImport___Win32_Release_45_DEBUG"
# PROP BASE Intermediate_Dir "BPTImport___Win32_Release_45_DEBUG"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "BPTImport___Win32_Release_45_DEBUG"
# PROP Intermediate_Dir "BPTImport___Win32_Release_45_DEBUG"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "D:\Grafik\Maya4.5\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NT_PLUGIN" /D "TIMER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /Gi /GX /ZI /Od /I "E:\Grafik\Maya4.5\include" /I "./" /D "DEBUG" /D "NT_PLUGIN" /D "TIMER" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /FAs /YX"BPTStableHeaders.h" /FD /c
# SUBTRACT CPP /X
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya4.5\lib\Foundation.lib D:\Grafik\Maya4.5\lib\OpenMaya.lib D:\Grafik\Maya4.5\lib\OpenMayaAnim.lib D:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"D:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyTools.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Glu32.lib opengl32.lib E:\Grafik\Maya4.5\lib\Foundation.lib E:\Grafik\Maya4.5\lib\OpenMaya.lib E:\Grafik\Maya4.5\lib\OpenMayaAnim.lib E:\Grafik\Maya4.5\lib\OpenMayaUI.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ./API_LIBS/Byronimo.lib /nologo /dll /incremental:yes /debug /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyTools.mll" /GZ /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BPTImport___Win32_Release_5"
# PROP BASE Intermediate_Dir "BPTImport___Win32_Release_5"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "BPTImport___Win32_Release_5"
# PROP Intermediate_Dir "BPTImport___Win32_Release_5"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "D:\Grafik\Maya4.5\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NT_PLUGIN" /D "TIMER" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "E:\Grafik\Maya5\include" /I "./" /D "NDEBUG" /D "NT_PLUGIN" /D "TIMER" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya4.5\lib\Foundation.lib D:\Grafik\Maya4.5\lib\OpenMaya.lib D:\Grafik\Maya4.5\lib\OpenMayaAnim.lib D:\Grafik\Maya4.5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"D:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyTools.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya5\lib\Foundation.lib E:\Grafik\Maya5\lib\OpenMaya.lib E:\Grafik\Maya5\lib\OpenMayaAnim.lib E:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyToolsM5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5_DEBUG"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BPTImport___Win32_Release_5_DEBUG"
# PROP BASE Intermediate_Dir "BPTImport___Win32_Release_5_DEBUG"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "BPTImport___Win32_Release_5_DEBUG"
# PROP Intermediate_Dir "BPTImport___Win32_Release_5_DEBUG"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "D:\Grafik\Maya5\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "NT_PLUGIN" /D "TIMER" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /ZI /Od /I "E:\Grafik\Maya5\include" /I "./" /D "DEBUG" /D "NT_PLUGIN" /D "TIMER" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /FAs /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib D:\Grafik\Maya5\lib\Foundation.lib D:\Grafik\Maya5\lib\OpenMaya.lib D:\Grafik\Maya5\lib\OpenMayaAnim.lib D:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"D:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyToolsM5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya5\lib\Foundation.lib E:\Grafik\Maya5\lib\OpenMaya.lib E:\Grafik\Maya5\lib\OpenMayaAnim.lib E:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /incremental:yes /debug /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyToolsM5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_6"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BPTImport___Win32_Release_6"
# PROP BASE Intermediate_Dir "BPTImport___Win32_Release_6"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "BPTImport___Win32_Release_6"
# PROP Intermediate_Dir "BPTImport___Win32_Release_6"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "E:\Grafik\Maya5\include" /I "./" /D "NDEBUG" /D "NT_PLUGIN" /D "TIMER" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /GX /O2 /I "E:\Grafik\Maya6\include" /I "./" /D "NDEBUG" /D "NT_PLUGIN" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ALPHA" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya5\lib\Foundation.lib E:\Grafik\Maya5\lib\OpenMaya.lib E:\Grafik\Maya5\lib\OpenMayaAnim.lib E:\Grafik\Maya5\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyToolsM5.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Glu32.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib E:\Grafik\Maya6\lib\Foundation.lib E:\Grafik\Maya6\lib\OpenMaya.lib E:\Grafik\Maya6\lib\OpenMayaAnim.lib E:\Grafik\Maya6\lib\OpenMayaUI.lib /nologo /dll /machine:I386 /out:"E:\P-R-O-J-E-K-T-E\ByronsPolyTools\Sources\Release\ByronsPolyToolsM6.mll" /export:initializePlugin /export:uninitializePlugin
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "BPTImport - Win32 Release"
# Name "BPTImport - Win32 Debug"
# Name "BPTImport - Win32 Release_45"
# Name "BPTImport - Win32 Release_45_DEBUG"
# Name "BPTImport - Win32 Release_5"
# Name "BPTImport - Win32 Release_5_DEBUG"
# Name "BPTImport - Win32 Release_6"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Nodes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BPT_insertVtxNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Byronimo.cpp
# End Source File
# Begin Source File

SOURCE=.\ByronsPolyToolsNode.cpp

!IF  "$(CFG)" == "BPTImport - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Debug"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45_DEBUG"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5_DEBUG"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_6"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fastTrgNode.cpp
# End Source File
# Begin Source File

SOURCE=.\softTransformationEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\softTransformationNode.cpp
# End Source File
# Begin Source File

SOURCE=.\visualizeMeshNode.cpp
# End Source File
# End Group
# Begin Group "Tools"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\interactiveValueTweakTool.cpp
# End Source File
# Begin Source File

SOURCE=.\softTransformationTool.cpp
# End Source File
# End Group
# Begin Group "Components"

# PROP Default_Filter ""
# Begin Group "Bevel"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\edge.cpp
# End Source File
# Begin Source File

SOURCE=.\edgeFaceData.cpp
# End Source File
# Begin Source File

SOURCE=.\endFaceData.cpp
# End Source File
# Begin Source File

SOURCE=.\nSelEdge.cpp
# End Source File
# Begin Source File

SOURCE=.\nSelEdgeData.cpp
# End Source File
# Begin Source File

SOURCE=.\selEdge.cpp
# End Source File
# End Group
# Begin Group "Split"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\face.cpp
# End Source File
# End Group
# End Group
# Begin Group "Factory"

# PROP Default_Filter ""
# Begin Group "BPTfty"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BPT_SMC.cpp

!IF  "$(CFG)" == "BPTImport - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Debug"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45_DEBUG"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5_DEBUG"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_6"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\BPTfty.cpp
# End Source File
# Begin Source File

SOURCE=.\BPTfty_NH.cpp
# End Source File
# Begin Source File

SOURCE=.\BPTftyAction.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\IVfty.cpp
# End Source File
# Begin Source File

SOURCE=.\vertexFty.cpp
# End Source File
# End Group
# Begin Group "Commands"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ByronsPolyToolsAction.cpp
# End Source File
# Begin Source File

SOURCE=.\ByronsPolyToolsInit.cpp
# End Source File
# End Group
# Begin Group "Creators"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\edgeMeshCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\IVMeshCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\meshCreator.cpp
# End Source File
# End Group
# Begin Group "Helpers"

# PROP Default_Filter ""
# Begin Group "LinkedList"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\baseNode.cpp
# End Source File
# Begin Source File

SOURCE=.\linkedNode.cpp
# End Source File
# Begin Source File

SOURCE=.\simpleLinkedList.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\componentConverter.cpp
# End Source File
# Begin Source File

SOURCE=.\dData.cpp
# End Source File
# Begin Source File

SOURCE=.\timer.cpp
# End Source File
# End Group
# Begin Group "PolyModifier"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\polyModifierCmd.cpp
# End Source File
# Begin Source File

SOURCE=.\polyModifierFty.cpp
# End Source File
# Begin Source File

SOURCE=.\polyModifierNode.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\cmgTranslator.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "NODES_header"

# PROP Default_Filter ""
# Begin Group "Bases"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\GLDrawNode.h
# End Source File
# Begin Source File

SOURCE=.\GLDrawNodeBase.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\BPT_insertVtxNode.h
# End Source File
# Begin Source File

SOURCE=.\Byronimo.h
# End Source File
# Begin Source File

SOURCE=.\ByronsPolyToolsNode.h
# End Source File
# Begin Source File

SOURCE=.\fastTrgNode.h
# End Source File
# Begin Source File

SOURCE=.\softTransformationEngine.h
# End Source File
# Begin Source File

SOURCE=.\softTransformationNode.h
# End Source File
# Begin Source File

SOURCE=.\visualizeMeshNode.h
# End Source File
# End Group
# Begin Group "HELPERS_header"

# PROP Default_Filter ""
# Begin Group "LinkedList No. 1"

# PROP Default_Filter ""
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\baseNode.h
# End Source File
# Begin Source File

SOURCE=.\linkedNode.h
# End Source File
# Begin Source File

SOURCE=.\simpleLinkedList.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\BPT_BA.h
# End Source File
# Begin Source File

SOURCE=.\BPT_Helpers.h
# End Source File
# Begin Source File

SOURCE=.\componentConverter.h
# End Source File
# Begin Source File

SOURCE=.\dData.h
# End Source File
# Begin Source File

SOURCE=.\progressBar.h
# End Source File
# Begin Source File

SOURCE=.\timer.h
# End Source File
# End Group
# Begin Group "TOOLS_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\interactiveValueTweakTool.h
# End Source File
# Begin Source File

SOURCE=.\softTransformationTool.h
# End Source File
# End Group
# Begin Group "COMPONENTS_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\edge.h
# End Source File
# Begin Source File

SOURCE=.\edgeFaceData.h
# End Source File
# Begin Source File

SOURCE=.\endFaceData.h
# End Source File
# Begin Source File

SOURCE=.\face.h
# End Source File
# Begin Source File

SOURCE=.\nSelEdge.h
# End Source File
# Begin Source File

SOURCE=.\nSelEdgeData.h
# End Source File
# Begin Source File

SOURCE=.\selEdge.h
# End Source File
# End Group
# Begin Group "POLYMODIFIER_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\polyModifierCmd.h
# End Source File
# Begin Source File

SOURCE=.\polyModifierFty.h
# End Source File
# Begin Source File

SOURCE=.\polyModifierNode.h
# End Source File
# End Group
# Begin Group "FACTORY_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BPTfty.h
# End Source File
# Begin Source File

SOURCE=.\BPTfty_NH.h
# End Source File
# Begin Source File

SOURCE=.\IVfty.h
# End Source File
# Begin Source File

SOURCE=.\vertexFty.h
# End Source File
# End Group
# Begin Group "COMMANDS_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ByronsPolyToolsCmd.h
# End Source File
# End Group
# Begin Group "CREATORS_header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\edgeMeshCreator.h
# End Source File
# Begin Source File

SOURCE=.\IVMeshCreator.h
# End Source File
# Begin Source File

SOURCE=.\meshCreator.h
# End Source File
# End Group
# Begin Group "GLOBALS_Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BCallback.h
# End Source File
# Begin Source File

SOURCE=.\BCallbackFunctions.h
# End Source File
# Begin Source File

SOURCE=.\BContext.h

!IF  "$(CFG)" == "BPTImport - Win32 Release"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Debug"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45_DEBUG"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5_DEBUG"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_6"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\BGlobals.h
# End Source File
# Begin Source File

SOURCE=.\BPTGlobalPrequesites.h
# End Source File
# Begin Source File

SOURCE=.\BPTStableHeaders.h

!IF  "$(CFG)" == "BPTImport - Win32 Release"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Debug"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_45_DEBUG"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_5_DEBUG"

!ELSEIF  "$(CFG)" == "BPTImport - Win32 Release_6"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "MANAGER_Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\manager.h
# End Source File
# Begin Source File

SOURCE=.\manipManager.h
# End Source File
# Begin Source File

SOURCE=.\UIManager.h
# End Source File
# End Group
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
# Begin Source File

SOURCE=.\BPTNodeManip.h
# End Source File
# Begin Source File

SOURCE=.\ByronsPolyToolsNodeManip.h
# End Source File
# Begin Source File

SOURCE=.\STEManp.h
# End Source File
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
# Begin Source File

SOURCE=.\cmgTranslator.h
# End Source File
# Begin Source File

SOURCE=.\MACROS.h
# End Source File
# Begin Source File

SOURCE=.\STEMacros.h
# End Source File
# End Group
# End Target
# End Project
