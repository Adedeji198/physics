
hWnd = CreateWindowEx(0,
	MainWndClass, 
	TEXT ("Physics Problems"),
	WS_OVERLAPPEDWINDOW|WS_VISIBLE|WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	706,
	636,
	NULL,
	NULL,
	hInst, 
	0
);

	hdc = GetDC(hWnd);
	logFont.lfHeight = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	logFont.lfWidth = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSX), 144);

	//logFont.lfHeight   = 0;
	//logFont.lfWidth = 0;
	
	logFont.lfEscapement = 0;
	logFont.lfOrientation = 0;

	logFont.lfUnderline = 0;
	logFont.lfStrikeOut = 0;

	logFont.lfOutPrecision = OUT_STRING_PRECIS;
	logFont.lfClipPrecision = CLIP_STROKE_PRECIS;
	logFont.lfQuality = DEFAULT_QUALITY;
	logFont.lfPitchAndFamily = FF_SWISS | VARIABLE_PITCH;
	

	logFont.lfWeight   = 400;
	logFont.lfItalic   = 255;
	logFont.lfCharSet  = 0;
	
	lstrcpy(logFont.lfFaceName, "Monotype Corsiva");


	g_font = CreateFontIndirect(&logFont); //get the font handle

