/* Windows Programming Tutorial Series
* from The Pentamollis Project
* 
**/
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
  MessageBox(NULL, "HELLO", "My first GUI", MB_OK);
  return 0;
}