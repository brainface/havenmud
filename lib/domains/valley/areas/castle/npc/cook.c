#include <lib.h>
inherit LIB_BARKEEP;
#include "../castle.h"

static void create() {
   barkeep::create();
   SetKeyName("castle cook");
   SetShort("the castle cook");
   SetId( ({ "cook" }) );
   SetAdjectives( ({ "castle" }) );
   SetLong("Sporting a rather portly belly, the cook has the "
           "hot, greasy look of someone locked up inside of "
           "a very warm kitchen all day long.");
   
   
   SetRace("dwarf");
   SetGender("male");
   SetMorality(-100);
   SetClass("rogue");
   SetLevel(17);
   SetLocalCurrency("nuggets");
   SetMenuItems( ([
                    "scotch" : "/std/meal/alcohol/scotch",
                    "beer" : VC_OBJ + "/beer",
                    "coffee" : VC_OBJ + "/coffee",
                    "bread" : "/std/meal/food/bread",
                    "yam" : VC_OBJ + "/yam",
               ]) );
}
