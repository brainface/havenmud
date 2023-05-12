#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("north sign");
   SetLong(
     "An impressively crafted sign sits to the north in front of the shop. "
   );
   SetRead("default", "Tim's Tin Trinkets"
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"metal"}) );
   SetAdjectives( ({ "north","shop" }) );
   SetKeyName("sign");
   SetPreventGet("The sign is securely bolted to the wall of the shop.");
}
