
// enum {} : esto nos servira para saber en que estado esta el personaje y poder realizar acciones. 
enum{
	WALK = 0
	
};


class Personaje : public Object{
	public:
		//variables
		int state;
		int dir;
		//funciones
		
		Personaje();
		~Personaje();
		const void action();
		void walk();
};


Personaje::Personaje(){
	
	this->y=150;
	this->x=80;
	this->w=32;
	this->h=32;
	this->fps=60;
	this->sprite = load_bitmap("img/personaje.bmp",NULL);
	this->state = WALK;
	this->dir = 0;
}


const void Personaje ::action(){
	switch(state){
		case WALK:
			this->walk();
		break;
	}
	animated(dir);
	//draw();
}

void Personaje::walk(){
	int mov_v = key[KEY_UP] - key[KEY_DOWN];
	int mov_h = key[KEY_LEFT] - key[KEY_RIGHT];
	
	if(mov_v == -1){
		y--;
		dir =3;
	}else if(mov_v == 1){
		y++;
		dir = 0;
	}else if(mov_h == -1){
		x--;
		dir =1;
		
	}else if(mov_h == 1){
		x++;
		dir=2;
	}
	
	if(!mov_v and !mov_h){
		fps = 0;
		this->index = 0;
		
	}else{
		
		fps =60;
	}
	
}

Personaje::~Personaje(){
	
}
