# Microsoft Developer Studio Project File - Name="nofrendo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=nofrendo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "nofrendo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nofrendo.mak" CFG="nofrendo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nofrendo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "nofrendo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "nofrendo - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "nofrendo - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /I ".." /I "..\nes" /I "..\sndhrdw" /I "..\libsnss" /I "..\cpu" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "nofrendo - Win32 Release"
# Name "nofrendo - Win32 Debug"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\bitmap.c
# End Source File
# Begin Source File

SOURCE=..\bitmap.h
# End Source File
# Begin Source File

SOURCE=..\config.c
# End Source File
# Begin Source File

SOURCE=..\event.c
# End Source File
# Begin Source File

SOURCE=..\event.h
# End Source File
# Begin Source File

SOURCE=..\gui.c
# End Source File
# Begin Source File

SOURCE=..\gui.h
# End Source File
# Begin Source File

SOURCE=..\gui_elem.c
# End Source File
# Begin Source File

SOURCE=..\gui_elem.h
# End Source File
# Begin Source File

SOURCE=..\intro.c
# End Source File
# Begin Source File

SOURCE=..\intro.h
# End Source File
# Begin Source File

SOURCE=..\log.c
# End Source File
# Begin Source File

SOURCE=..\log.h
# End Source File
# Begin Source File

SOURCE=..\Makefile
# End Source File
# Begin Source File

SOURCE=..\Makefile.am
# End Source File
# Begin Source File

SOURCE=..\Makefile.in
# End Source File
# Begin Source File

SOURCE=..\memguard.c
# End Source File
# Begin Source File

SOURCE=..\memguard.h
# End Source File
# Begin Source File

SOURCE=..\nofconfig.h
# End Source File
# Begin Source File

SOURCE=..\nofrendo.c
# End Source File
# Begin Source File

SOURCE=..\nofrendo.h
# End Source File
# Begin Source File

SOURCE=..\noftypes.h
# End Source File
# Begin Source File

SOURCE=..\osd.h
# End Source File
# Begin Source File

SOURCE=..\pcx.c
# End Source File
# Begin Source File

SOURCE=..\pcx.h
# End Source File
# Begin Source File

SOURCE=..\version.h
# End Source File
# Begin Source File

SOURCE=..\vid_drv.c
# End Source File
# Begin Source File

SOURCE=..\vid_drv.h
# End Source File
# End Group
# Begin Group "cpu"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\cpu\dis6502.c
# End Source File
# Begin Source File

SOURCE=..\cpu\dis6502.h
# End Source File
# Begin Source File

SOURCE=..\cpu\nes6502.c
# End Source File
# Begin Source File

SOURCE=..\cpu\nes6502.h
# End Source File
# End Group
# Begin Group "libsnss"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\libsnss\libsnss.c
# End Source File
# Begin Source File

SOURCE=..\libsnss\libsnss.h
# End Source File
# End Group
# Begin Group "nes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\nes\mmclist.c
# End Source File
# Begin Source File

SOURCE=..\nes\mmclist.h
# End Source File
# Begin Source File

SOURCE=..\nes\nes.c
# End Source File
# Begin Source File

SOURCE=..\nes\nes.h
# End Source File
# Begin Source File

SOURCE=..\nes\nes_mmc.c
# End Source File
# Begin Source File

SOURCE=..\nes\nes_mmc.h
# End Source File
# Begin Source File

SOURCE=..\nes\nes_pal.c
# End Source File
# Begin Source File

SOURCE=..\nes\nes_pal.h
# End Source File
# Begin Source File

SOURCE=..\nes\nes_ppu.c
# End Source File
# Begin Source File

SOURCE=..\nes\nes_ppu.h
# End Source File
# Begin Source File

SOURCE=..\nes\nes_rom.c
# End Source File
# Begin Source File

SOURCE=..\nes\nes_rom.h
# End Source File
# Begin Source File

SOURCE=..\nes\nesinput.c
# End Source File
# Begin Source File

SOURCE=..\nes\nesinput.h
# End Source File
# Begin Source File

SOURCE=..\nes\nesstate.c
# End Source File
# Begin Source File

SOURCE=..\nes\nesstate.h
# End Source File
# End Group
# Begin Group "mappers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\mappers\map000.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map001.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map002.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map003.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map004.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map005.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map007.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map008.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map009.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map011.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map015.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map016.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map018.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map019.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map024.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map032.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map033.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map034.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map040.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map041.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map042.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map046.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map050.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map064.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map065.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map066.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map070.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map073.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map075.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map078.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map079.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map085.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map087.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map093.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map094.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map099.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map160.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map229.c
# End Source File
# Begin Source File

SOURCE=..\mappers\map231.c
# End Source File
# Begin Source File

SOURCE=..\mappers\mapvrc.c
# End Source File
# End Group
# Begin Group "old"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\test\nofrendo.c

!IF  "$(CFG)" == "nofrendo - Win32 Release"

!ELSEIF  "$(CFG)" == "nofrendo - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "sdl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\sdl\sdl.c
# End Source File
# Begin Source File

SOURCE=..\sdl\sdl_api.c
# End Source File
# Begin Source File

SOURCE=..\sdl\sdl_api.h
# End Source File
# End Group
# Begin Group "sndhrdw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\sndhrdw\fds_snd.c
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\fds_snd.h
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\mmc5_snd.c
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\mmc5_snd.h
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\nes_apu.c
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\nes_apu.h
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\vrcvisnd.c
# End Source File
# Begin Source File

SOURCE=..\sndhrdw\vrcvisnd.h
# End Source File
# End Group
# Begin Group "win32"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\win32\osd.c
# End Source File
# Begin Source File

SOURCE=..\win32\rom.c
# End Source File
# End Group
# End Target
# End Project
