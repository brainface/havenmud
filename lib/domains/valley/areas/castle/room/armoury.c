#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the armoury");
   SetLong("The room is ordered, kept in neat shape to avoid the "
           "misplacing of bits and pieces of the armour being sold.  "
           "It appears that very little is also made or mended here, "
           "as there is no work area set aside or a door that leads into "
           "a back room.  A door does lead out to the open areas of the "
           "castle, however, to the south.");
   SetItems( ([
                ({ "armoury","room","castle" }) :
                   (: GetLong :),
                ({ "armour to be sold","armour","bits","bit","pieces",
                   "piece","bits of armour","bit of armour","piece of "
                   "armour","pieces of armour" }) :
                   "The armour is stowed beyond prying eyes.  It is "
                   "necessary that one asks the armourer, if one is "
                   "present, to browse, if one wishes to see a list "
                   "of merchandise.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/gen_02",
           ]) );
   SetInventory( ([
                    VC_NPC + "/armourer" : 1,
               ]) );
}
