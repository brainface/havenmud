#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small, basic room");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong("This is one of the several rooms in the Morning Star Inn.  While "
          "not greatly furnished, it does at least have a simple bed with "
          "moderately clean sheets next to the west wall.  There is a wooden "
          "sign securely nailed into the north wall.");
  SetItems( ([ 
             ({ "moderately clean sheets", "fairly clean sheets",
                "clean sheets", "sheets", "sheet" }) :
                "The sheets are fairly clean, though not exactly fresh.  "
                "They were last washed perhaps a week ago.",
             ({ "wooden sign", "sign" }) :
                "The wooden sign is nailed into the north wall and has the "
                "words, \"Any damage of property or theft on the premisis "
                "will be met with severe penalties.\"",
             ({ "simple bed", "bed" }) :
                "This is obviously not one of the most comfortable beds in "
                "the world, but it appears to be quite a bit better than "
                "the ground.",
             ({ "west wall", "north wall", "walls", "wall" }) :
                "The walls are very simple, unworthy of any attention."
             ]) );
  SetRead( ([
            ({ "wooden sign", "sign" }) :
               "Any damage of property or theft on the premisis will be met "
               "with severe penalties."
            ]) );
  SetInventory( ([ I_NPC + "/orc" : 1 ]) );
  SetObviousExits("east");
  SetExits( ([ "east" : I_ROOM + "/hall1" ]) );
  SetClimate("indoors");
}
