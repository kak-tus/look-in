/*
look-in
0.4.0.0

for aiki

Miranda IM plugin. One-page display user details
*/

#include <windows.h>
#include "../Miranda/SDK/headers_c/newpluginapi.h"
#include "Options.h"
#include "UserInfo.h"

HINSTANCE hInst;
PLUGINLINK *pluginLink;

PLUGININFO plgInfo = {
  sizeof(PLUGININFO),
  "look-in",
  PLUGIN_MAKE_VERSION(0, 4, 0, 0),
  "Adds an extra tab to the user details dialog to display all user details at only one page. For aiki",
  "look-in author",
  "look-in@mail.ru",
  "",
  "http://miranda-im.org/download/details.php?action=viewfile&id=1551",
  0,
  0
};

BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD Reason, LPVOID Reserved) {
  hInst = hInstance;
  return(TRUE);
}

extern "C" __declspec(dllexport) PLUGININFO* MirandaPluginInfo(DWORD MirandaVers) {
  return(&plgInfo);
}

extern "C" __declspec(dllexport) int Load(PLUGINLINK *Lnk) {
  pluginLink = Lnk;
  initOptions();
  initUserInfo();
  
  return(0);
}

extern "C" __declspec(dllexport) int Unload(void) {
  return(0);
}
