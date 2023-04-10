#include <windows.h>
#include "main_controller.h"
#include "main.h"
#include "resource.h"

HFONT    g_font;

// Our application entry point.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LOGFONT  logFont;
	HDC      hdc;

	hInst = hInstance;
	//HMENU hSysMenu;

	WNDCLASSEX  wc;
	LPCTSTR     MainWndClass = TEXT("physics-problems");
	HWND        hWnd;
	MSG         msg;

	// Class for our main window.
	wc.cbSize        = sizeof(wc);
	wc.style         = 0;
	wc.lpfnWndProc   = &wndProcMain;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	
	wc.hIcon         = (HICON) LoadImage(hInstance, 
		MAKEINTRESOURCE(IDI_APPICON), 
		IMAGE_ICON, 0, 0,
		LR_DEFAULTSIZE | LR_DEFAULTCOLOR | LR_SHARED
	);
	
	wc.hCursor       = (HCURSOR) LoadImage(
		NULL, IDC_ARROW, 
		IMAGE_CURSOR, 0, 0, 
		LR_SHARED
	);
	
	wc.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
	
	wc.lpszMenuName  = NULL;//Because we not making menu
	//wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
	wc.lpszClassName = MainWndClass;
	wc.hIconSm       = 0;

	// Register our window classes, or error.
	if (! RegisterClassEx(&wc))
	{
	MessageBox(NULL, TEXT("Error starting windows application."), TEXT("Error"), MB_ICONERROR | MB_OK);
	return 0;
	}

// Create instance of main window.
/*
	hWnd = CreateWindowEx(
		0, MainWndClass, MainWndClass, 
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		320, 200, NULL, NULL, 
		hInstance, NULL
	);

*/
#include "rc/main_layout.rcmain.c"


	if (! hWnd)
	{
	MessageBox(NULL, TEXT(" There was an error creating main window. Contact the app developer"), TEXT("Error"), MB_ICONERROR | MB_OK);
	return 0;
  }

  // Load accelerators.
  //hAccelerators = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR));


  // Show window and force a paint.
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  // Main message loop.
  while(GetMessage(&msg, NULL, 0, 0) > 0)
  {
  /*  if (! TranslateAccelerator(msg.hwnd, hAccelerators, &msg))
    {
 */
      TranslateMessage(&msg);
      DispatchMessage(&msg);
 /*   }  */
  }

  return (int) msg.wParam;
}