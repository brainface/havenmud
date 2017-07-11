#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("guardpost");
  SetLong( "Trees cover much of this large mudflat with well travelled "
           "trails leading between them into a more populated area of the "
           "mudflat as well as back towards the swamp." );

  SetItems( ([ "mud" : "The mud is such a dark shade of brown as to almost "
                       "be black.",
               "trails" : "Well trodden foot-trails lead off to the east "
                          "and southeast.",
               "trees" : "The trees around here have taken full advantage "
                         "of the dry land of the mudflat and are much more "
                         "numerous here than elsewhere.",
               "mudflat" : "The mudflat extends far to the south, but tapers "
                           "off to the north turning back into the swamp "
                           "that dominates the area."]) );

  SetExits( ([ "east" : GWONISH + "room/swamp10",
               "southeast" :  GWONISH + "room/swamp12"]) );

  SetInventory(([GWONISH + "npc/lizardmanguard.c": (random(3)+2)]) );
  if(!random(15))
    SetInventory(([GWONISH + "npc/r_swamp.c": (random(3)+1)]) );

  SetSmell( ([ "default" : "Wet rotting vegetation nearly overpowers your "
                           "olfactory system."]) );
  SetListen( ([ "default" : "The groan and croak of frogs fills the air." ]) );
  SetObviousExits("east, southeast");
}

