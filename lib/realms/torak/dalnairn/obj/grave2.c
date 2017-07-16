//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// Taken from a google search for grave jokes
// 

#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a stone marking");
   SetLong(
     "A flat stone marking is imbedded in the dirt. "
   );
   SetRead("default",
    "\n"
    "\n"
     "I made some good deals and\n"
     "I made some bad ones. I really\n"
     "went in the hole with this one.\n"
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"stone", "stone marking", "marking"}) );
   SetMaterials( ({"natural"}) );
   SetKeyName("stone");
   SetPreventGet("The stone marking can not be gotten.");
}
