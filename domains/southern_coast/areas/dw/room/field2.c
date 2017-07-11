#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetClimate("sub-arctic");
  SetDayLong("The light of day is bright, but not warm, here.  Off "
             "to the east is a large structure which stands in defiance "
             "of the ruined ground. In all directions but west, the "
             "ruined area leads into itself, while the ground continues "
             "its relentless attempts to destroy the ruins.");
  SetNightLong("The starlight shines down on the ruins in a manner "
               "that does nothing to cheer the somber scene which "
               "exists here.  To the east, a large structure stands "
               "in mute testimony to the past glory of this yard.");
  SetItems( ([
    ({ "ruin", "ruins" }) : "This area appears to have been a graveyard.",
    "structure" : "It looks like some kind of crypt.",
   ]) );
  SetSmell( ([
    "default" : "The smell of rotten land with decayed matter perfumes the air.",
  ]) );
  SetListen( ([
    "default" : "The area is deathly quiet.",
  ]) );
  SetInventory( ([
     NEWBIE_NPC + "/lowskel" : 3,
    ]) );
  SetDayLight(-10);
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field3",
     "east"  : NEWBIE_ROOM + "/field5",
     "south" : NEWBIE_ROOM + "/field1",
     ]) );
  }
