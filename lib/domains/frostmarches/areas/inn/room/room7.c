#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small room");
  SetAmbientLight(30);
  SetLong("This is the smallest room in the Morning Star Inn.  It is about "
          "the size of a prison cell and has barely enough room for the bed.  "
          "A lamp hanging from the ceiling provides a little light, but not "
          "much.  This room might not be good for extended stays.");
  SetItems( ([ 
             ({ "brass frame lamp", "brass lamp", "lamp" }) :
                "It is a brass frame lamp that provides barely adequate "
                "light for the room.",
             ({ "ceiling" }) :
                "The lamp does not provide enough light to get a good "
                "look at the ceiling.",
             ({ "barely adequate light", "adequate light", "light" }) :
                "The light from the lamp is barely enough to see.",
             ({ "medium bed", "soft bed", "medium sized bed", "bed" }) :
                "This is a medium sized, somewhat soft looking bed.  The "
                "sheets and blanket appear to have been set up recently.",
             ({ "sheets", "sheet", "blanket" }) :
                "The sheets and blanket appear to have been recently washed."
             ]) );
  SetObviousExits("west");
  SetExits( ([ "west" : I_ROOM + "/hall3" ]) );
  SetClimate("indoors");
}
