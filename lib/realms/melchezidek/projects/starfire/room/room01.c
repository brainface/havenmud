#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;
static void create() {
  ::create();
  SetClimate("indoors");
  SetWarmth(30);
  SetAmbientLight(15);
  SetShort("a dusty room below a sinkwell");
  SetLong(
      "This appears to be the end of a hallway. The southern portion is completely"
      " block off by sand but one could journey north. The walls are composed of"
      " blocks of a pale yellow stone held together by a yellow mortar. Some"
      " runes have been scratched hastily into the western wall."
      );
  SetItems( ([
	({ "brick", "block", "bricks", "blocks", "wall", "walls", "mortar", "stone" }) :
	  "The walls are composed of a series of yellow blocks held together by"
          " yellow mortar. The yellow color suggests both the blocks and mortar"
          " were made of sand.",
	({ "hallway", "room", "around" }) :
	  (: GetLong :),
	({ "rune", "runes" }) :
	  "These runes appear to have been hastily scratched into the walls"
 	  " and at a glance appear to be totally incomprehensible. Perhaps"
          " you should try to <read> them.",
        ({ "sand", "floor", "pile", "piles" }) :
          "The floor is covered with a thin layer of sand. In some spots it has collected"
          " into small piles making it hard to determine any specifics about the"
          " underlying construction.",
	]) );
  SetItemAdjectives( ([
	"brick" : ({ "yellow", "sand" }),
        "sand"  : ({ "thin", "piled" }),
	]) );
  SetExits( ([
      "north" : SF_ROOM "room02",
      "up"    : SF_ROOM_EXIT,
      ]) );
  SetRead("runes",
	"\n\n"
	"  Flee! We heard stories of the the ruins beneath the desert. We we....\n"
	"   ... not knowing exactly what we would find...    Now,\n"
        "   Fachiel is trapped and all I can hear are his muffl... screams\n"
        "   echoing through the wall.\n"
	"   I cannot save you, Fachiel! Forgive me!"
  );
 }
      
