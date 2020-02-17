class Object{
	
	public:
		//variables:
			float x;
			float y;
			BITMAP* sprite; // imagen que se le asigna al objeto.
			Alarm* System_alarm;
			int fps;    // velocidad de la animacion
			int w;  //ancho de la animacion. (frame)
			int h;  // largo de la animacion.(frame)
			int index;   //en que frame se encuentra.
		//function	
		Object();
		~Object();
		const virtual void action() = 0; // funcion virtual pura.
		void draw();
		void animated(int seccion);
		bool Mouse_Pressed(int b);
	
};
//la funcion virtual pura sirve para llamar la funcion de su clase heredara.

list<Object*>instancias;




Object::Object(){
	this->x      = 0;
	this->y      = 0;
	this->sprite = NULL;
	System_alarm = new Alarm[5]();
	this->fps    = 0;  //velocidad de cambio
	this->w      = 0;  // ancho de frame
	this->h      = 0;  // largo de frame
	this->index  = 0;  // en que frame se encuentra.
}

void Object::draw(){
	draw_sprite(lienzo,sprite,x,y);
}


//se libera memoria que este utilizando el sprite.
Object::~Object(){
	destroy_bitmap(this->sprite);
}


void Object::animated(int seccion){
	
	if(System_alarm[0].alarm(fps)){
		
		index >= sprite->w/w ? index = 0 : index ++;
		
	}
	
	masked_blit(sprite,lienzo,index * w, seccion * h, x, y, w, h);
}

bool Object::Mouse_Pressed(int b){
	if(mouse_b & b and Rango(x,x+w,mouse_x) and Rango(y,y+h,mouse_y)){
		return true;
		
	}else{
		return false;
	}
}

