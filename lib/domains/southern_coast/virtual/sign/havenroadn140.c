#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a painted sign");
   SetLong(
     "This sign bears a large shield emblazoned with a poorly painted red "
     "hawk. A phrase repeats itself in several languages below the image."
   );
   SetRead("default",
     "Kelan's Quality Armour"
   );
   //SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "wobbly","road" }) );
   SetKeyName("sign");
   SetPreventGet("The sign obstinately refuses to budge.");
}
