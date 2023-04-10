#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "rc/main_layout.rc.h"
#include "main_controller.h"

int   getRandom(int min,int max);
void  seed();
int   getRandomIndex();
int   getRandomSign();
//window procedure
LRESULT CALLBACK wndProcMain (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	
	
	 switch (message)
     {
		case   WM_CREATE: 
			drawMainWindow(hWnd, message, wParam, lParam);
		return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;

		case WM_COMMAND:
		switch( (int) LOWORD(wParam) ){
			case IDC_BTN1:
			showProblems(hWnd,(int) LOWORD(wParam), (HWND) lParam, (UINT)HIWORD(wParam) ); break;
		}
		return 0;
		case WM_PAINT:
			setFonts(hWnd);
		return DefWindowProc (hWnd, message, wParam, lParam) ;
		case WM_QUIT:
		case WM_CHAR:
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
		case WM_SYSKEYDOWN:
		case WM_INITDIALOG:
		case WM_SETFOCUS:
		case WM_KILLFOCUS:
		return DefWindowProc (hWnd, message, wParam, lParam) ;
	}	  
	
	
	return DefWindowProc (hWnd, message, wParam, lParam) ;
}

void setFonts (HWND hWnd){
	SendMessage(GetDlgItem( hWnd, IDC_EDT_OUTPUT), WM_SETFONT, (WPARAM)g_font, 0);
	SendMessage(GetDlgItem( hWnd, IDC_LST1), WM_SETFONT, (WPARAM)g_font, 0);
	SendMessage(GetDlgItem( hWnd, IDC_BTN1), WM_SETFONT, (WPARAM)g_font, 0);
}			

void drawMainWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	//HWND hCtrl0_0;
#include "rc/main_layout.rc.c"	
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "1. VASTU"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "2. Expans.."
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "3. Expans.2"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "4. Electric"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "5. Friction"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "6. Misile"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "7. Radians"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "8. Circular"
	);
    SendMessage (
		GetDlgItem (hWnd,  IDC_LST1), 
		LB_ADDSTRING, 0, (LPARAM) "9. Lens-Fmla"
	);
}

void showProblems(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify){
	int iIndex;

		iIndex = SendMessage (
			GetDlgItem (hwnd,  IDC_LST1),
			LB_GETCURSEL, 0, 0
		) ;

		switch(iIndex+1){
			case 1:
				showVastuProblem(hwnd);
			break;
			case 2:
				showExpansionProblem(hwnd);
			break;
			case 3:
				showExpansionProblem2(hwnd);
			break;
			case 4:
				showElectricProblem(hwnd);
			break;
			case 5:
				showFrictionProblem(hwnd);
			break;
			case 6:
				showProjectileProb(hwnd);
			break;
			case 7:
				showAngleProb(hwnd);
			break;
			case 8:
				showCirculaProb(hwnd);
			break;
			case 9:
				showLensProb(hwnd);
			break;
		}

}

void showVastuProblem(HWND hwnd){
	float v,a,s,t,u;
	
	int i;
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,10);

	for(i=0; i<10; i++){
		a = getRandom(5,50);
		u = getRandom(0,20);
		t = getRandom(5,30);

		v = u + a*t;
		s = u*t + 0.5f*a*t*t;

		sprintf(GG,"v=%4.2f a=%4.2f s=%4.2f t=%4.2f u=%4.2f \r\n",v,a,s,t,u);
		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);


}


void showExpansionProblem(HWND hwnd) {
	double Ex_Coeff[20],l1,l2,t1,t2;
	char *substance[20];

	int iIndex, i;

	char* G, *GG;

	Ex_Coeff[BRICK] = 5; 
	Ex_Coeff[CAST_IRON] = 10.8; 
	Ex_Coeff[COBALT] = 12; 
	Ex_Coeff[BRONZE] = 17.5; 
	Ex_Coeff[CONCRETE] = 13.5; 
	Ex_Coeff[COPPER] = 16.6; 
	Ex_Coeff[ALUMINIUM] = 23; 
	Ex_Coeff[GLASS] = 36;

	substance [BRICK] =   "Brick"; 
	substance [CAST_IRON] =   "Cast Iron"; 
	substance [COBALT] =   "Cobalt"; 
	substance [BRONZE] =   "Bronze"; 
	substance [CONCRETE] =   "Concrete"; 
	substance [COPPER] =   "Copper"; 
	substance [ALUMINIUM] =   "Aluminium"; 
	substance [GLASS] =   "Glass";

	G  = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,100);
	
	for(i=0; i<10;i++){
		iIndex = getRandom(0,GLASS);

		t1 = getRandom(20,100);
		t2 = getRandom(20,100);

		l1 = getRandom(5,25);

		l2 = l1 + Ex_Coeff[iIndex]* 1e-6*(t2-t1); 

		sprintf(GG,"l1=%4.2lf alpha=%4.2lfx10^-6 (%s) t1=%4.2lf t2=%4.2lf l2=%4.2lf \r\n\
\xf0l = %4.2e \xf0t =%4.2lf \r\n\r\n",
			l1,Ex_Coeff[iIndex],substance[iIndex],t1,t2,l2,l2-l1,t2-t1);

		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);

}


void showExpansionProblem2(HWND hwnd){
	double Ex_Coeff[20],Vl1,Vl2,Vc1,Vc2,t1,t2;
	char *substance[20];

	int iIndex,iIndex2, i;

	char* G, *GG;
	Ex_Coeff[BRICK] = 5; 
	Ex_Coeff[CAST_IRON] = 10.8; 
	Ex_Coeff[COBALT] = 12; 
	Ex_Coeff[BRONZE] = 17.5; 
	Ex_Coeff[CONCRETE] = 13.5; 
	Ex_Coeff[COPPER] = 16.6; 
	Ex_Coeff[ALUMINIUM] = 23; 
	Ex_Coeff[GLASS] = 36; 
	Ex_Coeff[ETHER] = 1650; 
	Ex_Coeff[ETHYL_ALCOHOL] = 1100; 
	Ex_Coeff[PETROL] = 950; 
	Ex_Coeff[GLYCERIN] = 500; 
	Ex_Coeff[MERCURY] = 180; 
	Ex_Coeff[WATER] = 210; 
	Ex_Coeff[AIR] = 3400; 

	substance [BRICK] =   "Brick"; 
	substance [CAST_IRON] =   "Cast Iron"; 
	substance [COBALT] =   "Cobalt"; 
	substance [BRONZE] =   "Bronze"; 
	substance [CONCRETE] =   "Concrete"; 
	substance [COPPER] =   "Copper"; 
	substance [ALUMINIUM] =   "Aluminium"; 
	substance [GLASS] =   "Glass"; 
	substance [ETHER] =   "Ether"; 
	substance [ETHYL_ALCOHOL] =   "Ethyl alcohol"; 
	substance [PETROL] =   "Petrol"; 
	substance [GLYCERIN] =   "Glycerin"; 
	substance [MERCURY] =   "Mercury"; 
	substance [WATER] =   "Water"; 
	substance [AIR] =   "Air"; 

	G  = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,100);

	for(i=0; i<5;i++){
		iIndex = getRandom(0,GLASS);

		t1 = getRandom(20,100);
		t2 = getRandom(20,100);

		Vc1 = getRandom(5,25);

		Vc2 = Vc1 + 3*Ex_Coeff[iIndex]* 1e-6*(t2-t1);

		iIndex2 = getRandom(ETHER,WATER);

		Vl1 = Vc1;

		Vl2 = Vl1 + Ex_Coeff[iIndex2]* 1e-6*(t2-t1);
		sprintf(GG,"Vl1=%4.2lf Vl2=%4.2lf gama=%4.2lf x10^-6 (%s) t1=%4.2lf t2=%4.2lf  \r\n\
Vc1=%4.2lf Vc2=%4.2lf alpha=%4.2lfx10^-6 (%s) \r\n\
\xf0Vl = %4.2e \xf0Vc==%4.2e \xf0t=%4.2lf   \r\n\r\n",
			Vl1,Vl2, Ex_Coeff[iIndex2],substance[iIndex2],t1,t2,
			Vc1,Vc2,Ex_Coeff[iIndex],substance[iIndex],
			Vl2-Vl1,Vc2-Vc1,t2-t1
			);

		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);

}

void showElectricProblem(HWND hwnd){
	float V,I,R,P;
	
	int i;
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,10);
	
	for(i=0; i<5; i++){
		I = getRandom(1,10);
		R = getRandom(10,40);
		V = I*R;
		P = V * I;


		sprintf(GG,"V=%4.2f, R= %4.2f, I = %4.2f, P = %4.2f\r\n",V,R,I,P);
		strcat(G,GG);
	}
	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);
}


void showFrictionProblem(HWND hwnd){
	float M,mu,F,W;
	
	int i;
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,10);
	for(i=0; i<10;i++){	
		mu = floor(getRandom(2,10)*100)/1000;
		M= getRandom(3,50);
		W = 10*M;
		F = mu * W;
		sprintf(GG,"M= %4.2f W=%4.2f, mu= %4.2f, F = %4.2f\r\n",M,W,mu,F);
		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);
}

void showProjectileProb(HWND hwnd){
	float u,g,H,T,theta,R;
	
	int i;
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,10);
	g= 9.8;

	for(i=0; i<10;i++){
		theta = getRandom(15,80);
		u=getRandom(20,100);
		T = 2*u*sin(theta*M_PI/180)/g;
		H = pow(u*sin(theta*M_PI/180),2)/(2*g);
		R = T*u*cos(theta*M_PI/180);

		sprintf(GG,"U= %4.2f \xf8= %4.2f T=%4.2f, H= %4.2f, R = %4.2f\r\n",u,theta,T,H,R);
		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);	
}

void showAngleProb(HWND hwnd){
	int Factors[] ={2,4,6,8,9,10,12,18,20,24,30,36,40,45,60,90,120,180};
	int iIndex;
	float theta,rad,ratio;
	int i;
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");
	
	seed();
	getRandom(10,10);
	for(i=0; i<10; i++){
		iIndex = getRandom(0,17);
		theta  = Factors[iIndex];
		ratio  = 360/theta;
		rad    = 2*M_PI/ratio;

		sprintf(GG,"\xf8 = %4.2f , = %4.2f rads(1/%4.2f \xF1) \r\n",theta,rad,ratio);
		strcat(G,GG);
	}
	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);		
}

void showCirculaProb(HWND hwnd){
	
	float theta,R,w,f,T,t;
	float ux,uy,U,D,A,Ax,Ay;
	float x,y;

	int i;
	
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");

	seed();
	getRandom(10,10);

	for(i=0;i<5;i++){
		R = getRandom(10,50);
		f = getRandom(15,100);
		T = 1/f;
		w = 2*M_PI*f;
		D = getRandom(10,300);	
		theta = D*M_PI/180;
		t     = theta/w;

		x = R*cos(theta);
		y = R*sin(theta);

		U = w*R/100;
		ux = -U * sin(theta);
		uy =  U * cos (theta);

		A = w*w*R;
		Ax = -A*cos(theta);
		Ay = -A*sin(theta);
		
		sprintf(GG,"R= %4.2fcm w= %3.2f f= %4.2f T=%4.2e  t=%4.2e \xf8=%4.2f(%4.1f)\
		\r\n x=%4.2f  y = %4.2f Ax=%4.2f Ay=%4.2f  \
	 	\r\nU=%4.2f Ux= %4.2f Uy= %4.2f\r\n\r\n",
			R,w,f,T,t,theta,D,x,y,Ax,Ay,U,ux,uy
		);
		strcat(G,GG);
	}

	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);

}


void showLensProb(HWND hwnd){
	int N,D,H;
	float f,v, k=5,u;
	int i;
	
	char* G, *GG;
	G = (char*) malloc(sizeof(char)*1024);
	GG = (char*) malloc(sizeof(char)*1024);

	strcpy(G,"");

	seed();
	getRandom(10,10);
	
	for(i=0; i<10;i++){
		v = getRandom(6,15);
		k = getRandom(2,10);
		u = (v*k)/(v-k);
		
		N = v*k;
		D = v-k;
		H = HCF(N,D);
		
		f = (u*v)/(u+v);

		sprintf(GG,"f=%4.2f, u=%4.2f (%d/%d), v=%4.2f\r\n",f,u,N/H,D/H,v);
		strcat(G,GG);
	}
	
	SetWindowText(GetDlgItem (hwnd,  IDC_EDT_OUTPUT), G	);
	free(G);
	free(GG);	

}

int HCF(int A, int B){
	int D = 2, H=1;

	do{
		while(A%D ==0 && B%D == 0){
			H *= D;
			A /=D;
			B /=D;
		}
		D++;
	}while(D<=(A) && D <= (B));

	return H;
}
