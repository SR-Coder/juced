/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-9 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

/*
    This file wraps together all the mac-specific code, so that
    we can include all the native headers just once, and compile all our
    platform-specific stuff in one big lump, keeping it out of the way of
    the rest of the codebase.
*/

#include "linux/juce_linux_NativeIncludes.h"

BEGIN_JUCE_NAMESPACE

#include "../io/files/juce_FileInputStream.h"
#include "../io/files/juce_FileOutputStream.h"
#include "../core/juce_SystemStats.h"
#include "../core/juce_Time.h"
#include "../core/juce_Random.h"
#include "../io/network/juce_URL.h"
#include "../io/files/juce_NamedPipe.h"
#include "../io/streams/juce_MemoryOutputStream.h"
#include "../threads/juce_InterProcessLock.h"
#include "../audio/devices/juce_AudioIODeviceType.h"
#include "../threads/juce_Thread.h"
#include "../threads/juce_ScopedLock.h"
#include "../io/files/juce_File.h"
#include "../core/juce_Singleton.h"
#include "../audio/dsp/juce_AudioDataConverters.h"
#include "../audio/audio_file_formats/juce_AudioCDReader.h"
#include "../gui/graphics/fonts/juce_Font.h"
#include "../io/streams/juce_MemoryInputStream.h"
#include "../io/files/juce_DirectoryIterator.h"
#include "../text/juce_XmlDocument.h"
#include "../utilities/juce_DeletedAtShutdown.h"
#include "../events/juce_MessageManager.h"
#include "../threads/juce_WaitableEvent.h"
#include "../threads/juce_Process.h"
#include "../gui/components/filebrowser/juce_FileChooser.h"
#include "../audio/devices/juce_MidiOutput.h"
#include "../audio/devices/juce_MidiInput.h"
#include "../text/juce_StringArray.h"
#include "../containers/juce_MemoryBlock.h"
#include "../core/juce_PlatformUtilities.h"
#include "../threads/juce_CriticalSection.h"
#include "../events/juce_Timer.h"
#include "../gui/components/special/juce_WebBrowserComponent.h"
#include "../gui/components/keyboard/juce_KeyPress.h"
#include "../utilities/juce_SystemClipboard.h"
#include "../gui/components/windows/juce_AlertWindow.h"
#include "../gui/components/special/juce_OpenGLComponent.h"
#include "../gui/components/juce_Desktop.h"
#include "../gui/components/juce_ComponentDeletionWatcher.h"
#include "../gui/graphics/geometry/juce_RectangleList.h"
#include "../gui/graphics/imaging/juce_ImageFileFormat.h"
#include "../gui/graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
#include "../gui/components/mouse/juce_DragAndDropContainer.h"
#include "../gui/components/special/juce_SystemTrayIconComponent.h"
#include "../application/juce_Application.h"

/* Remove this macro if you're having problems compiling the cpu affinity
   calls (the API for these has changed about quite a bit in various Linux
   versions, and a lot of distros seem to ship with obsolete versions)
*/
#if defined (CPU_ISSET) && ! defined (SUPPORT_AFFINITIES)
  #define SUPPORT_AFFINITIES 1
#endif

//==============================================================================
#define JUCE_INCLUDED_FILE 1

// Now include the actual code files..

#include "common/juce_posix_SharedCode.h"
#include "linux/juce_linux_Files.cpp"
#include "common/juce_posix_NamedPipe.cpp"
#include "linux/juce_linux_Network.cpp"
#include "linux/juce_linux_SystemStats.cpp"
#include "linux/juce_linux_Threads.cpp"

#if ! JUCE_ONLY_BUILD_CORE_LIBRARY
 #include "linux/juce_linux_Clipboard.cpp"
 #include "linux/juce_linux_Messaging.cpp"
 #include "linux/juce_linux_Fonts.cpp"
 #include "linux/juce_linux_Windowing.cpp"
 #include "linux/juce_linux_Audio.cpp"
 #include "linux/juce_linux_JackAudio.cpp"
 #include "linux/juce_linux_Midi.cpp"
 #include "linux/juce_linux_AudioCDReader.cpp"
 #include "linux/juce_linux_FileChooser.cpp"
 #include "linux/juce_linux_WebBrowserComponent.cpp"
#endif

END_JUCE_NAMESPACE
