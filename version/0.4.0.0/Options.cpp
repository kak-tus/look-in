#include <windows.h>
#include "../Miranda/SDK/headers_c/newpluginapi.h"
#include "../Miranda/SDK/headers_c/m_langpack.h"
#include "../Miranda/SDK/headers_c/m_database.h"
#include "resource.h"
#include "../Miranda/SDK/headers_c/m_options.h"
#include "../Miranda/SDK/headers_c/m_protocols.h"
#include <string.h>
#include "Const.h"

extern HINSTANCE hInst;

struct plPrTmpl {
  char *plugin;
  int protocol;
  char *templ;
};

plPrTmpl ppt[100];
int pptSize;

static BOOL CALLBACK optionsDlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  switch (Msg) {
    case WM_INITDIALOG: {
      TranslateDialogDefault(hWnd);

      if (DBGetContactSettingByte(0, "look-in", "hideUserInfoTabs", FALSE) == TRUE) {
        SendDlgItemMessage(hWnd, IDC_CB_HDTABS, BM_SETCHECK, BST_CHECKED, 0);
      }
      else {
        SendDlgItemMessage(hWnd, IDC_CB_HDTABS, BM_SETCHECK, BST_UNCHECKED, 0);
      }

      PROTOCOLDESCRIPTOR **prt; //плагины протоколов
      CallService(MS_PROTO_ENUMPROTOCOLS, (WPARAM)&pptSize, (LPARAM)&prt);
      
      for (int i = 0; i < pptSize; i++) {
        SendDlgItemMessage(hWnd, IDC_PLUGIN, LB_ADDSTRING, 0, (LPARAM)prt[i]->szName);

        #ifdef _DEBUG
        MessageBox(NULL, prt[i]->szName, "look-in", MB_OK);
        #endif

        ppt[i].plugin = strdup(prt[i]->szName);

        char *s = (char*)malloc(strlen(prt[i]->szName) + 9);
        strcpy(s, prt[i]->szName);
        strcat(s, "Protocol");
        ppt[i].protocol = DBGetContactSettingWord(0, "look-in", s, 0);
        if (ppt[i].protocol >= protocolSize || ppt[i].protocol < 0) {
          ppt[i].protocol = 0;
        }

        strcpy(s, prt[i]->szName);
        strcat(s, "Template");
        DBVARIANT dbv;
        if (!DBGetContactSetting(0, "look-in", s, &dbv)) {
          ppt[i].templ = strdup(dbv.pszVal);
          DBFreeVariant(&dbv);
        }
        else {
          ppt[i].templ = strdup(protocol[ppt[i].protocol].templ);
        }

        free(s);
      }

      for (i = 0; i < protocolSize; i++) { //протоколы
        SendDlgItemMessage(hWnd, IDC_PROTOCOL, CB_ADDSTRING, 0, (LPARAM)protocol[i].name);
      }

      char *s = (char*)malloc(MAX_PATH); //шаблоны
      GetModuleFileName(hInst, s, MAX_PATH);
      strrchr(s, '\\')[1] = 0;
      strcat(s, "template\\*.tmpl");
      WIN32_FIND_DATA fd;
      HANDLE h = FindFirstFile(s, &fd);
      if (h != INVALID_HANDLE_VALUE) {
        do {
          SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_ADDSTRING, 0, (LPARAM)&(fd.cFileName));
        } while (FindNextFile(h, &fd));
        FindClose(h);
      }
      free(s);

      return(TRUE);
    }
    case WM_COMMAND: {
      switch LOWORD(wParam) {
        case IDC_CB_HDTABS: {
          switch HIWORD(wParam) {
            case BN_CLICKED: {
              PostMessage(GetParent(hWnd), PSM_CHANGED, 0, 0);
              break;
            }
          }
          break;
        }
        case IDC_PLUGIN: {
          switch HIWORD(wParam) {
            case LBN_SELCHANGE: {
              int n = SendDlgItemMessage(hWnd, IDC_PLUGIN, LB_GETCURSEL, 0, 0);
              if (n == LB_ERR) {
                break;
              }
              SendDlgItemMessage(hWnd, IDC_PROTOCOL, CB_SETCURSEL, ppt[n].protocol, 0);
              int m = SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_FINDSTRING, -1, (LPARAM)ppt[n].templ);
              if (m == CB_ERR) {
                m = SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_FINDSTRING, -1, (LPARAM)protocol[ppt[n].protocol].templ);
                if (m == CB_ERR) {
                  m = -1;
                }
              }
              SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_SETCURSEL, m, 0);
              break;
            }
          }
          break;
        }
        case IDC_PROTOCOL: {
          switch HIWORD(wParam) {
            case CBN_SELCHANGE: {
              int n = SendDlgItemMessage(hWnd, IDC_PLUGIN, LB_GETCURSEL, 0, 0);
              if (n == LB_ERR) {
                break;
              }
              ppt[n].protocol = SendDlgItemMessage(hWnd, IDC_PROTOCOL, CB_GETCURSEL, 0, 0);
              PostMessage(GetParent(hWnd), PSM_CHANGED, 0, 0);
              break;
            }
          }
          break;
        }
        case IDC_TEMPLATE: {
          switch HIWORD(wParam) {
            case CBN_SELCHANGE: {
              int n = SendDlgItemMessage(hWnd, IDC_PLUGIN, LB_GETCURSEL, 0, 0);
              int m = SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_GETCURSEL, 0, 0);
              if (m == CB_ERR || n == LB_ERR) {
                break;
              }
              free(ppt[n].templ);
              ppt[n].templ = (char*)malloc(SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_GETLBTEXTLEN, m, 0) + 1);
              SendDlgItemMessage(hWnd, IDC_TEMPLATE, CB_GETLBTEXT, m, (LPARAM)ppt[n].templ);
              PostMessage(GetParent(hWnd), PSM_CHANGED, 0, 0);
              break;
            }
          }
          break;
        }
      }
      break;
    }
    case WM_DESTROY: {
      #ifdef _DEBUG
      MessageBox(NULL, "q", "look-in", MB_OK);
      #endif
      for (int i = 0; i < pptSize; i++) {
        free(ppt[i].templ);
        free(ppt[i].plugin);
      }
      break;
    }
    case WM_NOTIFY: {
      switch (((LPNMHDR)lParam)->idFrom) {
      case 0:
        switch (((LPNMHDR)lParam)->code) {
        case PSN_APPLY:
          if (SendDlgItemMessage(hWnd, IDC_CB_HDTABS, BM_GETCHECK, 0, 0) == BST_CHECKED) {
            DBWriteContactSettingByte(0, "look-in", "hideUserInfoTabs", TRUE);
          }
          else {
            DBWriteContactSettingByte(0, "look-in", "hideUserInfoTabs", FALSE);
          }

          for (int i = 0; i < pptSize; i++) {
            char *s = (char*)malloc(strlen(ppt[i].plugin) + 9);
            strcpy(s, ppt[i].plugin);
            strcat(s, "Protocol");
            DBWriteContactSettingWord(0, "look-in", s, ppt[i].protocol);
            strcpy(s, ppt[i].plugin);
            strcat(s, "Template");
            #ifdef _DEBUG
            MessageBox(NULL, s, "look-in", MB_OK);
            MessageBox(NULL, ppt[i].templ, "look-in", MB_OK);
            #endif
            DBWriteContactSettingString(0, "look-in", s, ppt[i].templ);
            free(s);
          }

          return(TRUE);
        }
        break;
      }
      break;
    }
  }

  return(FALSE);
}

static int initializeOptions(WPARAM wParam, LPARAM lParam) {
  OPTIONSDIALOGPAGE pg;

  pg.cbSize = sizeof(OPTIONSDIALOGPAGE);
  pg.position = 1000000000;
  pg.pszTitle = strdup("look-in");
  pg.pfnDlgProc = optionsDlgProc;
  pg.pszTemplate = MAKEINTRESOURCE(IDD_SETTDLG);
  pg.hInstance = hInst;
  pg.pszGroup = strdup("Plugins");
  pg.groupPosition = 1;
  pg.hGroupIcon = NULL;
  pg.flags = ODPF_BOLDGROUPS; //ODPF_SIMPLEONLY || ODPF_EXPERTONLY;
  pg.nIDBottomSimpleControl = 0;
  pg.nIDRightSimpleControl = 0;
  pg.expertOnlyControls = NULL;
  pg.nExpertOnlyControls = 0;

  CallService(MS_OPT_ADDPAGE, wParam, (LPARAM)(OPTIONSDIALOGPAGE*)&pg);
  return(0);
}

void initOptions(void) {
  HookEvent(ME_OPT_INITIALISE, initializeOptions);
}
