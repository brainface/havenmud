#include <domains.h>
#include <lib.h>
inherit LIB_ROOM;

void AddSpawns(int x, int y);

static void create(int x, int y) {
  string n, s, e, w;
  object boarder;
  int yes;
  ::create();
  SetClimate("arid");
  SetGoMessage("The desert is endless in that direction and travel there would be pointless.");
  SetShort("in the Xandrian Desert");
  SetLong( 
    "The endless desert looms into the distance to the south. The only inhabited lands on the "
    "continent of Xandria lie near the river Itro. Sand dunes stretch out nearly endlessly to "
    "to the south, east, and west."
    );
  
  /* Basic Exit Setup */
  n = XANDRIA_VIRTUAL + "desert/" + (x) + "," + (y + 1);
  s = XANDRIA_VIRTUAL + "desert/" + (x) + "," + (y - 1);
  w = XANDRIA_VIRTUAL + "desert/" + (x - 1) + "," + (y);
  e = XANDRIA_VIRTUAL + "desert/" + (x + 1) + "," + (y);
  
  if (y > -10) {
    AddLong(" To the north the sky gives the hint of a promise of water, "
            "and the threat of the endless Southern Sea.");
    }
  if (y == -10) {
    s = 0;
    AddLong(" The desert continues endlessly to the south, and further travel in that direction "
            "would be pointless.");
    }
  if (y == 0) {
    n = INNERSEA_VIRTUAL "ocean/" + x + ",-500";
    SetProperty("coastal", 1);
    AddLong(" Directly to the north lies the Southern Sea, a warm water ocean that lies peaceful "
            "and serene but is none the less insurmountable by the Xandrian nations.");
    }
  if (x == -500) w = XANDRIA_VIRTUAL "desert/500," + y;
  if (x ==  500) e = XANDRIA_VIRTUAL "desert/-500," + y;
  
  if (x > -20 && x < -2) {
    AddLong(" In the distance to the east the flood plains of the Itro River can be seen.");
  }
  if (x < 20 && x > 2) {
    AddLong(" In the distance to the west the flood plains of the Itro River can be seen.");
  }
  if (x == -2) {
    AddLong(" To the east lies the Itro river.");
    e = XANDRIA_VIRTUAL "river/-1," + y;
    }
  if (x == 2) {
    AddLong(" To the west lies the Itro river.");
    w = XANDRIA_VIRTUAL "river/1," + y;
    }
  if (y == -1 && x > -20 && x < 0) {
    AddLong(" To the south lie the walls of Lisht, the capital of the Xandrian Dynasty.");
    s = 0;
  }
  if (y ==  -10 && x > -20 && x < 0) {
    AddLong(" To the north lie the walls of Lisht, the capital of the Xandrian Dynasty.");
    n = 0;
  }
  if (x == -20 && y < -1 && y > -10) {
    AddLong(" To the east lie the walls of Lisht, the capital of the Xandrian Dynasty.");
    e = 0;
  }
  if (x == -20 && y == -10) {
    AddLong(" To the northeast lie the walls of Lisht, the capital of the Xandrian Dynasty.");
  }  
  if (x == -20 && y == -1) {
    AddLong(" To the southeast lie the walls of Lisht, the capital of the Xandrian Dynasty.");
  }  
  
  SetSmell("The desert air is crisp and odorless.");
  SetListen("Only the occasional sandy breeze breaks the silence.");
  
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  yes = 0;
  boarder = find_object(XANDRIA_VIRTUAL "tunnels/" + (x) + "," + (y));
  if (boarder) 
    if (boarder->GetExit("up")) yes = 1;
  
  if (!random(50) && (x < -20 || x > 20) || yes) {
    AddLong(" A large structure, which looks vaguely like some twisted form of anthill, opens here into a large tunnel.");
    AddItem("anthill", "This is a large opening into a tunnel beneath the desert.");
    AddItem("tunnel", "This tunnel leads down into the depths of the Xandrian desert.");
    AddEnter("tunnel", XANDRIA_VIRTUAL "tunnels/" + x + "," + y);
  }
  AddSpawns(x,y); // Add random wanderers
}

// adds spawn things to the desert.
//  thri-keen tunnels are still in desert.c
void AddSpawns(int x, int y) {
  // close desert (high mortal)
  if ((x < -20 && x > -100) || (x > 20 && x < 100)) {
    if (!random(10)) AddInventory(XANDRIA_VIRTUAL "/desert/dust_devil",random(3)+1);
    // slave hunter
    // escaped slave
  }

  // mid desert (legend)
  if ((x <= -100 && x > -250) || (x >= 100 && x < 250)) {
    if (!random(25)) AddInventory(XANDRIA_VIRTUAL "desert/manticore",random(3)+1);
    // gnoll nomad
    // elf rebel (stealthy dude)
  }

  // deep desert (avatar+)
  if ( x <= -250 || x >= 250 ) {
    // evil sandworm bastard
    if (!random(250)) AddInventory(XANDRIA_VIRTUAL "desert/worm", 1);  
    // elf prophet
    // scarab swarm
  }
  return;  
}
