/* Windows Programming Tutorial Series
* from The Pentamollis Project
* 
**/
#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);

HMENU hMenu;// global scope

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
  WNDCLASSW wc = {0};
  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hInstance = hInst;
  wc.lpszClassName = L"myWindowClass";
  wc.lpfnWndProc = WindowProcedure;
  
  if(!RegisterClassW(&wc))
  {
    return -1;
  }
  
  CreateWindowW(L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);
  
  MSG msg = {0};
  
  while(GetMessage(&msg, NULL, 0, 0))// replace NULL by 0 otherwise Warning
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  
  return 0;
}



LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
  switch (msg)
  {
    case WM_COMMAND:
      
      switch(wp)
      {
        case 1:
          MessageBeep(MB_OK);
        break;
      }
      
    break;
    
    case WM_CREATE:// when the window is created
      AddMenus(hWnd);
    break;
    
    case WM_DESTROY:
      PostQuitMessage(0);
    break;
    
    default:
      return DefWindowProcW(hWnd, msg, wp, lp);
  }
}

void AddMenus(HWND hWnd)
{
  hMenu = CreateMenu();
  
  AppendMenu(hMenu, MF_STRING, 1, "File");
  AppendMenu(hMenu, MF_STRING, 0, "Help");// null send a warning
  
  SetMenu(hWnd, hMenu);
}