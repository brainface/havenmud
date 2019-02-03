#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("well trampled area");
  SetLong( "The ground here is almost barren of vegetation, due to the "
           "amount of footprints tracked through the mud.  Many trees have "
           "been cut down, making this area a large clearing.  Well trampled "
           "trails lead off in many directions." );
  
  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trails" : "Well trodden foot-trails lead off to the east, "
                          "northwest and south.",
               "trees" : "Most of the trees have been cleared here, leaving "
                         "nothing but stumps.",
               "footprints" : "The prints are long and humanoid like, but "
                              "the toes seem longer and have left claw marks "
                              "in the mud.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );
  
  SetExits( ([ "east" : GWONISH + "room/swamp13",
               "south" : GWONISH + "room/swamp15",
               "northwest" :  GWONISH + "room/swamp11"]) );
  
  SetInventory(([GWONISH + "npc/lizardmanguard.c": (random(3)+2)]) );
  SetInventory(([GWONISH + "npc/lizardmanelite.c": 1]));
  if(!random(15))
    SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );
  
  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("east, south, northwest");
}
