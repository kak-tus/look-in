#include <string.h>
#include <stdlib.h>
#include <windows.h>

int setVariable(char **s, char *var, char *val) { //установка переменных в шаблоне
  char *r = *s;

  char *fv = (char*)malloc(100 + strlen(var)); //<tmplVar name="...">
  strcpy(fv, "<tmplVar name=\"");
  strcat(fv, var);
  strcat(fv, "\">");
  #ifdef _DEBUG
  MessageBox(NULL, fv, "look-in", MB_OK);
  #endif

  while (strstr(r, fv)) {
    char *p = strstr(r, fv);
    char *s1;
    if (val) {
      s1 = (char*)malloc(strlen(r) + strlen(val) + 1);
    }
    else {
      s1 = (char*)malloc(strlen(r) + 1);
    }
    strcpy(s1, r);
    s1[p - r] = 0;
    if (val) {
      strcat(s1, val);
    }
    strcat(s1, p + strlen(fv));
    free(r);
    r = s1;
  }
  #ifdef _DEBUG
  MessageBox(NULL, r, "look-in", MB_OK);
  #endif

  strcpy(fv, "<tmplIf name=\""); //<tmplIf name="..."><tmplElse></tmplIf>
  strcat(fv, var);
  strcat(fv, "\">");
  #ifdef _DEBUG
  MessageBox(NULL, fv, "look-in", MB_OK);
  #endif

  while (strstr(r, fv)) {
    char *p = strstr(r, fv);
    char *pIf = p;
    char *s1 = strdup(r);
    s1[p - r] = 0;
    int c = 1;
    char *pElse = NULL;
    while (c > 0) {
      if (c == 1 && !strstr(p + 1, "</tmplIf>")) {
        free(fv);
        free(s1);
        return(-1);
      }

      char *p1 = strstr(p + 1, "<tmplIf");
      char *p2 = strstr(p + 1, "<tmplElse>");
      char *p3 = strstr(p + 1, "</tmplIf>");
      #ifdef _DEBUG
      MessageBox(NULL, p1, "look-in", MB_OK);
      MessageBox(NULL, p2, "look-in", MB_OK);
      MessageBox(NULL, p3, "look-in", MB_OK);
      #endif

      if (p1 < p2) {
        if (p1) {
          p = p1;
        }
        else {
          p = p2;
        }
      }
      else {
        if (p2) {
          p = p2;
        }
        else {
          p = p1;
        }
      }
      if (p > p3) {
        p = p3;
      }
      else {
        if (!p1 && !p2) {
          p = p3;
        }
      }

      if (!p1 && !p2 && !p3) {
        free(fv);
        free(s1);
        return(-1);
      }

      if (p == p1) {
        c++;
      }
      if (p == p3) {
        c--;
      }
      if (p == p2 && c == 1) {
        pElse = p;
      }
    }
    char *pSIf = p;
    
    if (val) {
      if (pElse) {
        strncat(s1, pIf + strlen(fv), pElse - pIf - strlen(fv));
      }
      else {
        strncat(s1, pIf + strlen(fv), pSIf - pIf - strlen(fv));
      }
    }
    else {
      if (pElse) {
        strncat(s1, pElse + 10, pSIf - pElse - 10);
      }
    }
    
    strcat(s1, pSIf + 9);
    free(r);
    r = s1;
  }

  free(fv);

  *s = r;
  return(0);
}

int cutTags(char **s) { //вырезать необработанные теги
  /*char *r = *s;

  char CRLF[] = {13, 10, 0}; //вырезать CR LF
  while (strstr(r, (char*)&CRLF)) {
    char *p = strstr(r, (char*)&CRLF);
    char *s1 = strdup(r);
    s1[p - r] = 0;
    strcat(s1, p + 2);
    free(r);
    r = s1;
  }

  char BR[] = "<tmplBr>"; //заменить <tmplBr> на CR LF
  while (strstr(r, (char*)&BR)) {
    char *p = strstr(r, (char*)&BR);
    char *s1 = strdup(r);
    s1[p - r] = 0;
    strcat(s1, (char*)&CRLF);
    strcat(s1, p + 8);
    free(r);
    r = s1;
  }

  *s = r;*/
  return(0);
}