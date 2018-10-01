//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// Taken from a google search for grave jokes
// 

#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a polished gravestone");
   SetLong(
     "A polished gravestone is imbedded in the dirt. "
   );
   SetRead("default",
    "\n"
     "\nDawn Under\n"
     "\n"
     "Here lies my wife\n"
     "I bid her Goodbye\n"
     "She rests in peace\n"
     "And now so do I\n"
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"gravestone"}) );
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "polished" }) );
   SetKeyName("gravestone");
   SetPreventGet("The gravestone can not be gotten.");
}
