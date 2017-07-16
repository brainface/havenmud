#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("guardpost");
  SetLong( "The mudflat runs right up to the base of the cliff here with "
           "trails leading off through the trees in westerly and southerly "
           "directions." );
  
  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trails" : "Well trodden foot-trails lead off to the west "
                          "and south.",
               "cliff" : "Rock and mud tower above you in a series of cliffs "
                         "making up the great palisades that ring most of "
                         "the area.",
               "palisades" : "The series of cliffs extend far to the south "
                             "and wrap around to the west in the north as "
                             "well.",
               "trees" : "The trees around here have taken full advantage "
                         "of the dry land of the mudflat and are much more "
                         "numerous here than elsewhere.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );
  
  SetExits( ([ "west" : GWONISH + "room/swamp12",
               "northwest" : GWONISH + "room/swamp10",
               "south" :  GWONISH + "room/swamp14"]) );
  
  SetInventory(([GWONISH + "npc/lizardmanguard.c": (random(3)+2)]) );
  if(!random(15))
    SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );
  
  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("west, south, northwest");
}
