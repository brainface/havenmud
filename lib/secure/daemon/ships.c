/*  Vehicle Daemon, to load vehicles upon player login */
#include <lib.h>
#include <save.h>
inherit LIB_DAEMON;

int CheckShip(object);
object *Ships;

static void create() {
	::create();
	SetNoClean(1);
	Ships = ({ });
}

void PlayerLogin(object player) {
	string dir = SAVE_VEHICLES + "/" + player->GetKeyName();
	string *tmp, *ships;
	string file;
	object ship;

  if (file_size(dir + "/") != -2)  { return; }
  tmp = get_dir(dir + "/"); // letters of ship names
  foreach(string letter in tmp) {
  	ships = get_dir(dir + "/" + letter + "/");
  
  	foreach(string shipfile in ships) {
  		file = read_file(dir + "/" + letter + "/" + shipfile , 0, 1);
  
  		if (file) file = file[1..(sizeof(file)- 2)];
  		ship = 0;
  		ship = new(file);
  
   		if (ship) {
   			ship->RestoreVehicle(dir + "/" + letter + "/" + shipfile);
   			if (CheckShip(ship)) { 
  	    	ship->eventMove(ship->GetCurrentLocation());
  	    } 
  	  }
    }
  }
}


int CheckShip(object ship) {
	object local = load_object(ship->GetCurrentLocation());
	object *stuff = ({ });
	
	if (!local) {
		ship->eventDestruct();
		return 0;
	}
	stuff = all_inventory(local);
	foreach (object thing in stuff) {
		if (thing->GetVehicleName() == ship->GetVehicleName()) {
			ship->eventDestruct();
			return 0;
		}
	}
	Ships += ({ ship });
	return 1;
}

object *GetShips() {	
	Ships = filter(Ships, (: $1 :) );
	return Ships;
}

object *AddShip(object ship) {
	Ships = distinct_array(Ships + ({ ship }));
	return GetShips();
}

void PlayerLogout(object player) {
  object *ships = GetShips();
  ships = filter(ships, (: $1 :) );
  foreach(object ship in ships) {
    if (ship->GetOwner() == player->GetKeyName()) {
      ship->SaveVehicle();
      
    }
  }
}
  