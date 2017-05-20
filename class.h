//common client/server classes
class vector2{//obvious shit
	float x;
	float y;
	public:
	vector2(float x, float y);
	float x();
	float y();
	float length();
	float normalized();
	//pls someone implement operator= here
}

class world_item{//obstacle or any item placed on map like loot etc
	std::string type; //type defines sprite etc
	std::string name; //in case it is unique
	vector2 position;
	vector2 size;
	int initialised;
	int moveable; //for sure walls heve 0, but some boxes can be moveable and have 1 in this field
	public:
	void set(std::string type,vector2 pos, vector2 size,std::string name="noname_ent");
	vector2 move(vector2 direction); //returns new position of entity. if is not moveable returns vec2(-1,-1)
}

class map_sector{//for drawing the map
	std::string type;
	vector2 position; //size must be the same every time. position is relative to map
	int initialised;
	public:
	void set(std::string type, vector2 pos);
	void change_type(std::string type);
	std::string type();
	vector2 pos();
}

class map{
	map_sector sectors[MAP_SIZE_X][MAP_SIZE_Y]
	int initialised;
	public:
	void init(const char* mapdata); //need to make char array with sector data and send to this
									//made so, because this class is to be used both on server and client
}

class weapon{
	bool ammo;//if weapon with ammunition true, otherwise false
	std::string image;//path to image;
	float range;
	float damage;

}
class inventory_item{
	std::string image;
	std::string description;
	int count;//amount
	bool empty;
	bool locked;
public:
	inventory_item(bool _locked=true,bool _empty=true,std::string _image="",std::string _description="",int _count=0)
		:empty(_empty),locked(_locked),image(_image),description(_description),count(_count)
		{};
}

class character{
	float hp;
	float stamina;
	inventory_item inventory[MAX_COUNT_INVENTORY];
	float range_vision;
	float speed;
	//мб все ниже закинуть в один класс
	? left_hand;
	? right_hand;
	? off_hand;
	? body;
	? head;
public:
	character(float _hp=100.,float _stamina=100.,const int inventory_count=10,float _range_vision=10.,float _speed=4.)
		:hp(_hp),stamina(_stamina),range_vision(_range_vision),speed(_speed){
			bool inventory_lock[inventory_count]={};
			inventory_item inventory[MAX_COUNT_INVENTORY]={inventory_lock};
	}
}


//HAVENT CHANGED AFTER THIS

RASCHODNIKI,ARMOR	наследуются от item