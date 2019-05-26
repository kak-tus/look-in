#include <windows.h>
#include "../Miranda/SDK/headers_c/newpluginapi.h"
#include "../Miranda/SDK/headers_c/m_langpack.h"
#include "../Miranda/SDK/headers_c/m_database.h"
#include <stdio.h>
#include "../Miranda/SDK/headers_c/statusmodes.h"
#include "Const.h"
#include "Template.h"
#include "resource.h"
#include "../Miranda/SDK/headers_c/m_userinfo.h"
#include "../Miranda/SDK/headers_c/m_system.h"
#include <time.h>

//HANDLE hContact;
extern HINSTANCE hInst;

/*struct UserItem {
  HWND hWnd;
  HANDLE hContact;
};

UserItem user[100];
int userSz = 0;*/

static void showUserInfo(HWND hWnd, HANDLE hContact) {
  DBVARIANT dbv;

  #ifdef _DEBUG
  MessageBox(NULL, MSNInternalTemplate, "look-in", MB_OK);
  #endif

  char *prt = NULL;

  if (!DBGetContactSetting(hContact, "Protocol", "p", &dbv)) {
    prt = strdup(dbv.pszVal);
    DBFreeVariant(&dbv);
  }
  else {
    return;
  }

  #ifdef _DEBUG
  MessageBox(NULL, prt, "look-in", MB_OK);
  #endif

  char *s = (char*)malloc(strlen(prt) + 9);
  strcpy(s, prt);
  strcat(s, "Protocol");
  int proto = DBGetContactSettingWord(0, "look-in", s, 0);
  if (proto >= protocolSize || proto < 0) {
    proto = 0;
  }

  char *templ;
  strcpy(s, prt);
  strcat(s, "Template");
  if (!DBGetContactSetting(0, "look-in", s, &dbv)) {
    templ = strdup(dbv.pszVal);
    DBFreeVariant(&dbv);
  }
  else {
    templ = strdup(/*protocol[proto].templ*/intTempl[intTemplSz - 1].name);
  }
  free(s);

  #ifdef _DEBUG
  MessageBox(NULL, templ, "look-in", MB_OK);
  #endif

  char *tmpl = NULL;
  bool b = false;

  for (int i = 0; i < intTemplSz; i++) {
    if (strcmp(templ, intTempl[i].name) == 0) {
      b = true;
      tmpl = strdup(intTempl[i].templ);
      break;
    }
  }

  if (!b) { //если не используется внутренний шаблон
    s = (char*)malloc(MAX_PATH);
    GetModuleFileName(hInst, s, MAX_PATH);
    strrchr(s, '\\')[1] = 0;
    strcat(s, "template\\");
    strcat(s, templ);

    #ifdef _DEBUG
    MessageBox(NULL, s, "look-in", MB_OK);
    #endif

    FILE *fs = fopen(s, "rb");
    free(s);

    if (fs == NULL) {
      return;
    }

    #ifdef _DEBUG
    MessageBox(NULL, "Template file opened", "look-in", MB_OK);
    #endif

    fseek(fs, 0, SEEK_END);
    long sz = ftell(fs);
    fseek(fs, 0, SEEK_SET);

    tmpl = (char*)malloc(sz + 1);
    if (!tmpl) {
      return;
    }
    memset(tmpl, 0, sz + 1);

    if ((long)fread(tmpl, 1, sz, fs) != sz) {
      free(tmpl);
      fclose(fs);
      return;
    }
    fclose(fs);
  }

  free(templ);

  InfoListItem *ili = protocol[proto].list;

  for (i = 0; i < protocol[proto].listSize; i++) {
    #ifdef _DEBUG
    MessageBox(NULL, ili[i].DBName, "look-in", MB_OK);
    #endif
    switch (ili[i].DBType) {
      case ILSTRING: {
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          setVariable(&tmpl, ili[i].DBName, dbv.pszVal);
          DBFreeVariant(&dbv);
        }
        else {
          setVariable(&tmpl, ili[i].DBName, NULL);
        }

        break;
      }
      case ILLISTBYTE: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          ListItem *li = ili[i].list;
          for (int j = 0; j < ili[i].listSize; j++) {
            #ifdef _DEBUG
            MessageBox(NULL, li[j].value, "look-in", MB_OK);
            #endif
            if (li[j].id == dbv.bVal) {
              v = strdup(Translate(li[j].value));
              break;
            }
          }
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILLISTWORD: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          ListItem *li = ili[i].list;
          for (int j = 0; j < ili[i].listSize; j++) {
            #ifdef _DEBUG
            MessageBox(NULL, li[j].value, "look-in", MB_OK);
            #endif
            if (li[j].id == dbv.wVal) {
              v = strdup(Translate(li[j].value));
              break;
            }
          }
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILBYTE: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          v = (char*)malloc(17);
          itoa(dbv.bVal, v, 10);
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILWORD: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          v = (char*)malloc(33);
          ltoa(dbv.wVal, v, 10);
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILDWORD: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          v = (char*)malloc(33);
          ltoa(dbv.dVal, v, 10);
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILIP: {
        char *v = NULL;
        DWORD IP = DBGetContactSettingDword(hContact, prt, ili[i].DBName, 0);
        if (IP != 0) {
          in_addr ina;
          ina.S_un.S_un_b.s_b1 = HIBYTE(HIWORD(IP));
          ina.S_un.S_un_b.s_b2 = LOBYTE(HIWORD(IP));
          ina.S_un.S_un_b.s_b3 = HIBYTE(LOWORD(IP));
          ina.S_un.S_un_b.s_b4 = LOBYTE(LOWORD(IP));
          v = strdup(inet_ntoa(ina));
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILBIRTHDAY: {
        char *v = NULL;
        ListItem *li = ili[i].list;
        int bDay = DBGetContactSettingByte(hContact, prt, li[0].value, 0);
        int bMonth = DBGetContactSettingByte(hContact, prt, li[1].value, 0);
        int bYear = DBGetContactSettingWord(hContact, prt, li[2].value, 0);
        if (bDay != 0 && bMonth != 0 && bYear != 0) {
          v = (char*)malloc(100);
          SYSTEMTIME tm = {bYear, bMonth, 0, bDay, 0, 0, 0, 0};
          GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, &tm, NULL, v, 100);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILDATETIME: {
        char *v = NULL;
        long t = DBGetContactSettingDword(hContact, prt, ili[i].DBName, 0);
        if (t != 0) {
          tm *otm = localtime(&t);
          SYSTEMTIME stm = {otm->tm_year + 1900, otm->tm_mon + 1, 0, otm->tm_mday, otm->tm_hour, otm->tm_min, otm->tm_sec, 0};
          v = (char*)malloc(100);
          char dtS[49], tmS[49];
          GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, &stm, NULL, (char*)&dtS, 49);
          GetTimeFormat(LOCALE_USER_DEFAULT, 0, &stm, NULL, (char*)&tmS, 49);
          strcpy(v, (char*)&dtS);
          strcat(v, (char*)&tmS);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILNOTES: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, "UserInfo", ili[i].DBName, &dbv)) {
          v = strdup(dbv.pszVal);
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      case ILTIMEZONE: {
        char *v = NULL;
        if (!DBGetContactSetting(hContact, prt, ili[i].DBName, &dbv)) {
          if ((char)dbv.bVal != -100) { //почти весь код из Miranda-IM/ui/userinfo/stdinfo.c
            int tmz = (char)dbv.bVal;
            FILETIME ft;
            GetSystemTimeAsFileTime(&ft);
            LARGE_INTEGER li;
            li.QuadPart =* (__int64*)&ft;
            li.QuadPart -= (__int64)tmz * 30i64 * 60i64 * 10000000i64;
            *(__int64*)&ft = li.QuadPart;
            SYSTEMTIME st;
            FileTimeToSystemTime(&ft, &st);
            char s[100];
            GetTimeFormat(LOCALE_USER_DEFAULT, 0, &st, NULL, (char*)&s, 100);
            setVariable(&tmpl, "Localtime", (char*)&s);
            v = (char*)malloc(10);
            sprintf(v, (char)dbv.bVal?"GMT%+d:%02d":"GMT", - (char)dbv.bVal / 2, ((char)dbv.bVal & 1) * 30);
          }
          DBFreeVariant(&dbv);
        }
        setVariable(&tmpl, ili[i].DBName, v);
        if (v != NULL) free(v);
        break;
      }
      default: {
        setVariable(&tmpl, ili[i].DBName, NULL);
        break;
      }
    }
  }

  /*

  if (!DBGetContactSetting(hContact, "UserInfo", "Mye-mail0", &el)) { //пользовательские e-mail адреса
    vl[j] = (char*)malloc(strlen(Translate("Other e-mails:")) + strlen(el.pszVal) + 2);
    strcpy(vl[j], Translate("Other e-mails:"));
    strcat(vl[j], " ");
    strcat(vl[j], el.pszVal);
    DBFreeVariant(&el);

    int i = 1;
    char s[17];
    itoa(i, (char*)&s, 10);
    char s2[8 + 17 + 1];
    strcpy((char*)&s2, "Mye-mail");
    strcat((char*)&s2, (char*)&s);

    while(!DBGetContactSetting(hContact, "UserInfo", (char*)&s2, &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], "; ");
      strcat(vl[j], el.pszVal);

      i++;
      itoa(i, (char*)&s, 10);
      strcpy((char*)&s2, "Mye-mail");
      strcat((char*)&s2, (char*)&s);

      DBFreeVariant(&el);
    }
    
    j++;
  }

  if (!DBGetContactSetting(hContact, "UserInfo", "MyPhone0", &el)) { //пользовательские номера телефонов
    vl[j] = (char*)malloc(strlen(Translate("Other phone numbers:")) + strlen(el.pszVal) + 2);
    strcpy(vl[j], Translate("Other phone numbers:"));
    strcat(vl[j], " ");
    strcat(vl[j], el.pszVal);
    DBFreeVariant(&el);

    int i = 1;
    char s[17];
    itoa(i, (char*)&s, 10);
    char s2[7 + 17 + 1];
    strcpy((char*)&s2, "MyPhone");
    strcat(s2, (char*)&s);

    while(!DBGetContactSetting(hContact, "UserInfo", (char*)&s2, &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], "; ");
      strcat(vl[j], el.pszVal);

      i++;
      itoa(i, (char*)&s, 10);
      strcpy((char*)&s2, "MyPhone");
      strcat((char*)&s2, (char*)&s);

      DBFreeVariant(&el);
    }
    j++;
  }

  if (!DBGetContactSetting(hContact, prt, "Past0", &el)) { //past background
    vl[j] = (char*)malloc(strlen(Translate("Past background:")) + strlen(el.pszVal) + 2);
    strcpy(vl[j], Translate("Past background:"));
    strcat(vl[j], " ");
    strcat(vl[j], el.pszVal);
    DBFreeVariant(&el);

    if (!DBGetContactSetting(hContact, prt, "Past0Text", &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], ": ");
      strcat(vl[j], el.pszVal);
      DBFreeVariant(&el);
    }

    int i = 1;
    char s[11];
    itoa(i, (char*)&s, 10);
    char s2[4 + 11 + 4];
    strcpy((char*)&s2, "Past");
    strcat((char*)&s2, (char*)&s);

    while(!DBGetContactSetting(hContact, prt, s2, &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], "; ");
      strcat(vl[j], el.pszVal);
      DBFreeVariant(&el);

      strcpy((char*)&s2, "Past");
      strcat((char*)&s2, (char*)&s);
      strcat((char*)&s2, "Text");
      
      if (!DBGetContactSetting(hContact, prt, s2, &el)) {
        vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

        strcat(vl[j], ": ");
        strcat(vl[j], el.pszVal);
        DBFreeVariant(&el);
      }


      i++;
      itoa(i, (char*)&s, 10);
      strcpy((char*)&s2, "Past");
      strcat((char*)&s2, (char*)&s);
    }

    j++;
  }

  if (!DBGetContactSetting(hContact, prt, "Interest0Cat", &el)) { //интересы
    vl[j] = (char*)malloc(strlen(Translate("Interests:")) + strlen(el.pszVal) + 2);
    strcpy(vl[j], Translate("Interests:"));
    strcat(vl[j], " ");
    strcat(vl[j], el.pszVal);
    DBFreeVariant(&el);
    
    if (!DBGetContactSetting(hContact, prt, "Interest0Text", &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], ": ");
      strcat(vl[j], el.pszVal);
      DBFreeVariant(&el);
    }

    int i = 1;
    char s[11];
    itoa(i, (char*)&s, 10);
    char s2[8 + 11 + 4];
    strcpy((char*)&s2, "Interest");
    strcat((char*)&s2, (char*)&s);
    strcat((char*)&s2, "Cat");

    while(!DBGetContactSetting(hContact, prt, s2, &el)) {
      vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

      strcat(vl[j], "; ");
      strcat(vl[j], el.pszVal);
      DBFreeVariant(&el);

      strcpy((char*)&s2, "Interest");
      strcat((char*)&s2, (char*)&s);
      strcat((char*)&s2, "Text");
      
      if (!DBGetContactSetting(hContact, prt, s2, &el)) {
        vl[j] = (char*)realloc(vl[j], strlen(vl[j]) + 3 + strlen(el.pszVal));

        strcat(vl[j], ": ");
        strcat(vl[j], el.pszVal);
        DBFreeVariant(&el);
      }

      i++;
      itoa(i, (char*)&s, 10);
      strcpy((char*)&s2, "Interest");
      strcat((char*)&s2, (char*)&s);
      strcat((char*)&s2, "Cat");
    }

    j++;
  }

  */

  cutTags(&tmpl);

  if (tmpl) {
    SetDlgItemText(hWnd, IDC_MD_EDT, tmpl);
    free(tmpl);
  }

  if (prt != NULL) free(prt);

  return;
}

static BOOL CALLBACK userInfoDlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  switch (Msg){
    case WM_INITDIALOG: {
      TranslateDialogDefault(hWnd);
      showUserInfo(hWnd, (HANDLE)lParam);
      return(TRUE);
    }
    case WM_NOTIFY: {
      switch (((LPNMHDR)lParam)->idFrom) {
        case 0: {
          switch (((LPNMHDR)lParam)->code) {
            case PSN_INFOCHANGED: {
              showUserInfo(hWnd, (HANDLE)lParam);
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  
  return(FALSE);
}

static void hideUserInfoTabs(WPARAM wParam, char *protocol) {
  if (DBGetContactSettingByte(0, "look-in", "hideUserInfoTabs", FALSE) == FALSE) {
    return;
  }

  struct DetailsPageInit {
    int pageCount;
    OPTIONSDIALOGPAGE *odp;
  }; 
  struct DetailsPageInit *opi = (struct DetailsPageInit*)wParam;
  struct DetailsPageInit opi2;
  opi2.pageCount = 0;
  opi2.odp = NULL;

  for (int i = 0; i < opi->pageCount; i++) {
    if (strcmp(opi->odp[i].pszTitle, "Summary") != 0 && strcmp(opi->odp[i].pszTitle, protocol) != 0 && strcmp(opi->odp[i].pszTitle, "Contact") != 0 && strcmp(opi->odp[i].pszTitle, "Location") != 0 && strcmp(opi->odp[i].pszTitle, "Work") != 0 && strcmp(opi->odp[i].pszTitle, "Background") != 0 && strcmp(opi->odp[i].pszTitle, "Notes") != 0) {
      opi2.odp = (OPTIONSDIALOGPAGE*)realloc(opi2.odp, sizeof(OPTIONSDIALOGPAGE) * (opi2.pageCount + 1));
      opi2.odp[opi2.pageCount].cbSize = sizeof(OPTIONSDIALOGPAGE);
      opi2.odp[opi2.pageCount].hInstance = opi->odp[i].hInstance;
      opi2.odp[opi2.pageCount].pfnDlgProc = opi->odp[i].pfnDlgProc;
      opi2.odp[opi2.pageCount].position = opi->odp[i].position;
      opi2.odp[opi2.pageCount].pszTitle = opi->odp[i].pszTitle;
      opi2.odp[opi2.pageCount].pszTemplate = opi->odp[i].pszTemplate;
      opi2.odp[opi2.pageCount].pszGroup = opi->odp[i].pszGroup;
      opi2.odp[opi2.pageCount].groupPosition = opi->odp[i].groupPosition;
      opi2.odp[opi2.pageCount].hGroupIcon = opi->odp[i].hGroupIcon;
      opi2.odp[opi2.pageCount].hIcon = opi->odp[i].hIcon;
      opi2.pageCount++;
    }
    else {
      free(opi->odp[i].pszTitle);
      if (opi->odp[i].pszGroup != NULL) free(opi->odp[i].pszGroup);
      if((DWORD)opi->odp[i].pszTemplate & 0xFFFF0000) free(opi->odp[i].pszTemplate);
    }
  }

  free(opi->odp);
  opi->pageCount = opi2.pageCount;
  opi->odp = opi2.odp;

  return;
}

static int initializeUserInfo(WPARAM wParam, LPARAM lParam) {
  HANDLE hContact = (HANDLE)lParam;
  if (hContact == 0) return(0);

  char *prt = NULL;

  DBVARIANT dbv;
  if (!DBGetContactSetting(hContact, "Protocol", "p", &dbv)) {
    prt = strdup(dbv.pszVal);
    DBFreeVariant(&dbv);
  }
  else {
    return(0);
  }

  OPTIONSDIALOGPAGE pg;
  
  pg.cbSize = sizeof(pg);
  pg.position = 2000000000;
  pg.pszTitle = "look-in";
  pg.pfnDlgProc = userInfoDlgProc;
  pg.pszTemplate = MAKEINTRESOURCE(IDD_UIDLG);
  pg.hInstance = hInst;
  pg.hIcon = NULL;
  CallService(MS_USERINFO_ADDPAGE, wParam, (LPARAM)&pg);

  hideUserInfoTabs(wParam, prt);

  if (prt != NULL) free(prt);

  return(0);
}

static int loadedModules(WPARAM wParam, LPARAM lParam) {
  HookEvent(ME_USERINFO_INITIALISE, initializeUserInfo);
  return(0);
}

void initUserInfo(void) {
  HookEvent(ME_SYSTEM_MODULESLOADED, loadedModules);
}