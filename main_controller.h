void drawMainWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wndProcMain (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
extern HINSTANCE hInst;
void setFonts (HWND hWnd);
	void showProblems(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

void showVastuProblem(HWND hwnd);

enum subst {
BRICK, 
CAST_IRON, 
COBALT, 
BRONZE, 
CONCRETE, 
COPPER, 
ALUMINIUM, 
GLASS, 
ETHER, 
ETHYL_ALCOHOL, 
PETROL, 
GLYCERIN, 
MERCURY, 
WATER, 
AIR
};

 
void showExpansionProblem(HWND hwnd) ;
void showExpansionProblem2(HWND hwnd);
void showExpansionProblem2(HWND hwnd);
void showElectricProblem(HWND hWnd);
void showFrictionProblem(HWND hwnd);
void showProjectileProb(HWND hwnd);
void showAngleProb(HWND hwnd);
void showCirculaProb(HWND hwnd);
void showLensProb(HWND hwnd);
int HCF(int A, int B);