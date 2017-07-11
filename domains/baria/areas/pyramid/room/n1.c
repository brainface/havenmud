
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: n1.c
// Area: the dark pyramid
//

#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("along the northern side of the pyramid");
  SetLong(
    "Most of the sight of the wall to the north is "
    "obstructed by a large jade statue. At both sides of "
    "the sarcophagus, a small torch hangs from the wall "
    "and gives this area a decent illumination. To the "
    "south, a dark chasm extends further in that way. "
    "The stones forming the floor continue west and east."
  );
  SetItems( ([
    ({"area"}) : (: GetLong :),
    ({"walls","wall"}) : "The walls seem to be made out of a perfectly-cut "
    	"dark stone.",
    ({"chasm","pit"}) : "A dark bottomless pit forms and extends to the south.",
    ({"ground","floor"}) : "The floor is made up of stones tiled together.",
    ({"torch","torches"}) : "A small torch hangs on either side of the "
    	"jade sarcophagus, together producing a small amount of light.",
    ({"stone","stones"}) : "A very dark type of stone forms the walls "
    	"and floor.",
    ({"statue", "sarcophagus"}) : "A large jaguar-like statue made out of "
    	"jade blocks part of the northern wall.",
  ]) );
  SetItemAdjectives( ([
    "walls" : ({"stone","obstructed"}),
    "chasm" : ({"dark","bottomless"}),
    "floor" : ({"tiled"}),
    "torch" : ({"small"}),
    "stone" : ({"dark","grey","tiled"}),
    "statue" :({"large","jaguar-like","jade"})
  ]) );
  SetExits( ([ 
    "east" : P_ROOM + "/inter_n2",
    "west" : P_ROOM + "/nw",
  ]) );
  SetSmell( ([ 
    "default" : "There's a disgusting odor of rottenness."
  ]) ); 
  SetListen( ([ 
    "default" : "The sounds of loud crying are heard." 
  ]) ); 
}
