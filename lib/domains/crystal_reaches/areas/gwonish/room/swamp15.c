#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("nesting area");
  SetLong( "Shallow holes are dug out all about the area.  Many are filled "
           "with layers of grass or leaves.  The perimeter is defined by "
           "well picked over bones that have been tossed away.  Trails "
           "continue to crisscross this area like the rest of the "
           "surrounding mudflat." );
  
  SetItems( ([ ({"holes","nest","nests",}) :
               "Worn smooth the holes appear to be nests of some sort.",
               "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trails" : "Well trodden foot-trails lead off to the north "
                          "and south.",
               "bones" : "Although most of the bones are humanoid in shape "
                         "and texture, they are very small.  Almost all that "
                         "you see are bleached white with age, but a few "
                         "still hold the stain of blood",
               "trees" : "Most of the trees have been cleared here, leaving "
                         "nothing but stumps.",
               "footprints" : "The prints are long and humanoid like, but "
                              "the toes seem longer and have left claw marks "
                              "in the mud.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );
  
  SetExits( ([ "north" : GWONISH + "room/swamp12",
               "south" : GWONISH + "room/swamp16"]) );
  
  SetInventory(([GWONISH + "npc/lizardmanguard.c": (random(3)+1)]) );
  SetInventory(([GWONISH + "npc/r_lizardman.c" : (random(5)+1)]));
  SetInventory(([GWONISH + "npc/lizardmanelite.c": 1]));
  if(!random(15))
    SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );
  
  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("north, south");
}
