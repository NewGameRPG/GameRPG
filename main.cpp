#include <allegro.h>
#include <list>
using namespace std;
BITMAP* lienzo;
#include "Function.h"
#include "Alarm.h"
#include "Object.h"
#include "Personaje.h"


void init();
void deinit();

int main() 
{ 
	init();
 	lienzo = create_bitmap(SCREEN_W,SCREEN_H);
 	instancias.push_back(new Personaje()); // agregar un personaje a la lista.
       
//-------------------------------- o -------------------------------------	
 // Looping until the ESCape key is pressed.
 while(! key[KEY_ESC]){
 	
 	for(list<Object*>::iterator it =instancias.begin(); it != instancias.end();it ++)
 	{
 		Object *other = *it;
 		other->action();
	 }
 	draw_sprite(screen,lienzo,0,0); 
 	clear_to_color(lienzo,0xffffff); //limia el ienzo de color blanco
 
 }
 // Exit program.
 deinit();
 allegro_exit();
 return 0;     
}     

void init(){
	int depth, res;
	allegro_init();   // Initialize Allegro. 
	depth = desktop_color_depth();
	if(depth == 0){
		depth = 32;
	}
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640,480,0,0);
	if(res !=0){
		allegro_message(allegro_error);
		exit(-1);
	}
	
	install_timer();
	install_keyboard();
	install_mouse();
	show_mouse(screen);
}

void deinit(){
	clear_keybuf();
}

// Some Allegro magic to deal with WinMain().
END_OF_MAIN();
// Imprime el texto en la pantalla.
 //textout(screen, font, "Hello World!", 1, 1, 10);
 //textout(screen, font, "Press ESCape to quit.", 1, 12, 11);
