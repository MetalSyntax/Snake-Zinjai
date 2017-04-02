#include "Header.h" //Cabecera Personalizada

using namespace std;

///Posicionador
void gotoxy(int x,int y){  
	HANDLE hcon;  
	COORD dwPos;  
	
	dwPos.X = x;  
	dwPos.Y= y;  
	
	hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(hcon,dwPos);  
}  
///Cursor
void OcultaCursor() {
	CONSOLE_CURSOR_INFO cci = {100, FALSE}; // El segundo miembro de la estructura indica si se muestra el cursor o no.
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


///Pantalla Ajustada
bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;
	
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;
	
	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);
	
	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}

bool AjustarVentana(int Ancho, int Alto);

///Terreno
void lot(void){
	//Cuadro Horizontal
	for (int i=2;i<78;i=i+1){
		gotoxy(i,3); printf("%c",205);
		gotoxy(i,23); printf("%c",205);
	}
	//Cuadro Vertical
	for (int i=4;i<23;i=i+1){
		gotoxy(2,i); printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}
	//Esquinas
	gotoxy(2,3); printf("%c",201);
	gotoxy(2,23); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,23); printf("%c",188);
}

///Posicion
void save_pos(void){
	body[n][0] = x;
	body[n][1] = y;
	n=n+1;
	if(n == tam) n = 1;
}

///Dibujo del cuerpo
void body_paint(void){
	for(int i=1;i<tam;i=i+1){
		gotoxy(body [i][0], body [i][1]); printf("*");
	}
}

///Borrar Cuerpo
void delete_body(){
	gotoxy(body [n][0], body [n][1]); printf(" ");
}

///Puntuacion
void record(){
	gotoxy(3,1);
	printf("Score %d",score);
}
///Cambio de Velocidad
void change_speed(){
	if(score == h*20){
		speed -=10;
		h++;
	}
}

///comida
void food(){
	if (x == xc && y == yc){
		xc = (rand()%71)+5;
		yc = (rand()%18)+5;
		
		tam++;
		score +=10;
		gotoxy(xc,yc);printf("o");
		
		change_speed();
	}
}

///Teclado
void typting(){
	if(kbhit()){
		key = getch();
		switch(key){
		case ARRIBA: if(dir != 2)dir = 1;
		break;
		case ABAJO: if(dir != 1)dir = 2;
		break;
		case DERECHA: if(dir != 4)dir = 3;
		break;
		case IZQUIERDA: if(dir != 3)dir = 4;
		}
	}
}
///Segundo Teclado Experimental
void typting2(){
	if(kbhit()){
		switch(key){
		case 'w': if(dir != 2)dir = 1;
		break;
		case 's': if(dir != 1)dir = 2;
		break;
		case 'd': if(dir != 4)dir = 3;
		break;
		case 'a': if(dir != 3)dir = 4;
		}
	}
}
///cambiar posicion
void change_pos(){
	if (dir == 1) y--;
	if (dir == 2) y++;
	if (dir == 3) x++;
	if (dir == 4) x--;
}

///Mensaje de Carga y Presentacion
void intro(void){ 
	system("cls");
	system("Color 03");
	AjustarVentana(80,25); 
	cout<<"                                                                      "<<endl;
	cout<<"       A A           AAAA AA   A AAAA A A   AAAA                      "<<endl;
	cout<<"        A            A    A A  A A  A AAA   A                         "<<endl;
	cout<<"        A            A    A  A A AAAA A  A  AAA                       "<<endl;
	cout<<"      AAAAA          A    A   AA A  A A   A A                         "<<endl;
	cout<<"     A AAA A     AAAAA    A   AA A  A A   A AAAA                      "<<endl;
	cout<<"    AAAAAAAAA                                                         "<<endl;
	cout<<"    AAAAAAAAA                                                         "<<endl;
	cout<<"     AAAAAAA           AAAAAAAAAAA               AAAAAAAAAAAAAAAA     "<<endl;
	cout<<"     AAAAAAA          AAAAAAAAAAAAAA            AAAAAAAAAAAAAAAAAA    "<<endl;
	cout<<"      AAAAAAA        AAAAAAAAAAAAAAAA          AAAAAAAAAAAAAAAAAA     "<<endl;
	cout<<"       AAAAAAA      AAAAAA     AAAAAAA        AAAAAAA                 "<<endl;
	cout<<"        AAAAAAA    AAAAAA       AAAAAAA      AAAAAA                   "<<endl;
	cout<<"         AAAAAAAAAAAAAAA         AAAAAAAAAAAAAAAAA                    "<<endl;
	cout<<"          AAAAAAAAAAAAA           AAAAAAAAAAAAAAA                     "<<endl;
	cout<<"           AAAAAAAAAAA             AAAAAAAAAAAAA                      "<<endl;
	cout<<"                                                                      "<<endl;
	Sleep(1500);
	system("cls");	
}

///Instrucciones del Juego
void Rules(void){
	system("cls");
	cout<<"1.- Utilizar Flechas del Teclado para Moverse"<<endl;
	cout<<"2.- Tocar los muros o el cuerpo propio hara que termine el Juego "<<endl;
	cout<<"3.- Solo Tienes una Vida. Provechala al Maximo"<<endl;
	cout<<"4.- Que se Diviertan"<<endl;
	Sleep(3500);
	system("cls");
}

bool game_over(void){
	if(y == 3 || y == 23 || x == 2 || x == 77) return false ;
	for (int j=tam-1;j>0;j=j-1){
		if(body[j][0] == x && body[j][1] ==y) return false;
	}
	return true;
}

void End_Game(void){
	
	gotoxy(0,1);
	clock_t t;
	t=clock_t();
	t=clock()-t;
	cout<<"Duracion de la Partida: "<<int(t)/CLOCKS_PER_SEC<<" Segundos"<<endl;
	
	cout<<"Puntuacion: "<<score<<" Puntos"<<endl;
	
	cout<<"\n\n\n Created By MetalSyntax";
	Sleep(2000);
}

//Programa Principal

int main () {	
	
	OcultaCursor();
	
	AjustarVentana(80,25); 
	
	intro();
	
	Rules();
	
	lot();
	
	gotoxy(xc,yc);printf("o");
	
	do {
		
		delete_body();
		
		save_pos();
		
		body_paint();
		
		food();
		
		record();
		
		typting();
		typting();
		
		change_pos();
		
		Sleep(speed);
		
		
	} while(key != ESC && game_over());

	system("cls");
	
	End_Game();
		
	return 0;
}


