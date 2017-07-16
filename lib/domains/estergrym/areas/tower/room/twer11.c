
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("north");
  SetShort("necromancers lair");
  SetLong(
          "The lair is large and very spacious with its dark "
          "magic lingering about. The carpet wraps around this "
          "circular room covering the ground from wall to wall. "
          "Cackling black flames creep off the torches which float "
          "only a few inches from the walls. A "
          "throne rests against the south wall with a window "
          "directly behind it giving a birds eye view of the "
          "Estergrym Mountain range to the east. A large black flag "
          "is visible through the window whipping through the "
          "strong winds.");
  SetExits( ([
            "north"          : TOWER_ROOMS "twer10",   
           ]) );
  SetSmell( ([
            "default" : "The smell of death and decay strongly lingers.",
           ]) );
  SetListen( ([
            "default" : "The torches flare up and hiss loudly.",
           ]) );
  SetInventory(([ 
                  TOWER_NPC "necromancer" : 1,
                  TOWER_NPC "shrieker" : 1,
				  TOWER_OBJ "rtorch" : 2,
              ]));
  SetItems( ([
     ({ "tower","lair" }) : (: GetLong :),
     ({ "doorway" }) : "The doorway is made of wood "
                       "and provides passage to the north. It has strange "
                       "runes which glow with what appears to be red "
                       "embers.",  
     "window"    : "The window is triangular in shape and shows a great "
                   "view of the north road and the Estergrym Mountains. "
                   "A large black flag whips in the wind through the "
                   "tower but it is barely visible.",
     "throne"    : "This throne has been composed of a dark black wood "
                   "which has simple vertical carvings of lines along the "
                   "back rest and skulls for the arm rest, a true "
                   "throne for a necromancer. It faces the doorway to "
                   "the north.",
     "ceiling"   : "The ceiling is flat and bare and it is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other and "
                   "follow the hallway south and the steps downward.",
     "walls"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. A window not covered by anything "
                    "has been placed in the south wall revealing "
                    "some of the outside terrain.",
    ({ "ground", "floor" }) : "The floor has been lined with a "
                               "red carpet and it lines the walls "
                               "edge to edge. A throne rests on "
                               "the floor facing the north.",
    ({ "carpet" }) : "The red carpet is plain and "
                                    "simple. It covers the floor "
                                    "wall to wall. On top of it "
                                    "near the south is a throne.",
    ({ "flag" }) : "This "
                    "triangular black flag rests out of view "
                    "through the window. It is simple and "
					"lacks any decor or designs.",
     "wood"  : "The dark black wood on the throne is polished "
	           "and gives off a shimmer.",
     "runes" : "The runes embedded on the doorway glow with "
	           "a soft red light. They appear ancient elvish.",
     "road"  : "The North Road can be seen outside the window "
	           "to the east.",
     "wall"  : "The wall has been made of square cut stone "
	           "slabs. There is a doorway in the north "
			   "wall.",
	 "view"  : "The view outside the window shows the Estergrym "
	           "Mountains and the north road which is barely seen "
			   "due to the terrain and sheer distance from here.",
              ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "flat","bare","stone" }),
    "carpet" : ({ "red" }),
    "floor" : ({ "carpet","red" }),
    "ground" : ({ "carpet","red" }),
    "walls" : ({ "black","stone"}),
    "runes" : ({ "glowing" }),
    "flag" : ({ "black","large","triangular" }),
    "doorway" : ({ "ornate" }),
    "wood" : ({ "dark","black" }),
  ]) );
}