#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the kitchen");
   SetLong("Every good house needs a kitchen, and this one serves as "
           "such for the farm house here.  A small table for about "
           "four people is prepared for a meal.  A window peers out "
           "towards the south, at the Ruined Sea.  A doorway is to the "
           "east, leading into the living room.");
   SetItems( ([
                ({ "eastern doorway","doorway" }) :
                   "The doorway doesn't have a door attached to it at "
                   "the moment, so it provides clear open access to the "
                   "east.",
                ({ "farm house kitchen","kitchen","room" }) :
                   (: GetLong :),
                ({ "good house","house","living room","door" }) :
                   "Try as one might, it is impossible to view that "
                   "at this angle.",
                ({ "small table","table" }) :
                   "Four table settings have been places at each side "
                   "of this square table.",
                ({ "four table settings","table settings","settings",
                   "setting","table setting" }) :
                   "The table has these four table settings on it, "
                   "each set up for a meal in the exact same way.",
                ({ "south window","window" }) :
                   "Light from the window shines into the kitchen, "
                   "and the Ruined Sea can be viewed from it.",
                ({ "ruined sea","sea" }) :
                   "The Ruined Sea is a barren waste.",
           ]) );
   SetExits( ([
                "east" : SDM_ROOM + "/living",
           ]) );
   SetObviousExits("east");
   SetInventory( ([
                    SDM_NPC + "/mother" : 1,
               ]) );
}