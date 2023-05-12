#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("south sign");
   SetLong(
     "An sign in the shape of a cupcake adorns the cafe door on the south side of the "
     "road. It is a pink cupcake with white frosting. And a cherry-on-top. "
   );
   SetRead("default", "Sandy's Succulent Sweets"
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "south", "cafe", "sweet", "cupcake" }) );
   SetKeyName("sign");
   SetPreventGet("The sign is enchanted and will not come off.");
}
