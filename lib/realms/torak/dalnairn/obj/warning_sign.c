//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a wooden sign");
   SetLong(
     "A painted wooden warning sign has been erected here. "
   );
   SetRead("default",
     "\n%^RED%^BOLD%^         WARNING%^RESET%^\n"
     "\n"
     "%^CYAN%^BOLD%^     Shifting Tides%^RESET%^\n"
     "%^WHITE%^BOLD%^No Sleeping on the Beach%^RESET%^\n"
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "wooden","painted","warning" }) );
   SetKeyName("sign");
   SetPreventGet("The sign refuses to budge.");
}
