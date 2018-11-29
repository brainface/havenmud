#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a painted sign");
   SetLong(
     "A comically large white needle, the paint faded with wear, threads "
     "through a shapeless brown bag on the face of this wooden sign. A phrase "
     "repeats itself in several languages below the image."
   );
   SetRead("default",
     "Tornys' Leather Emporium"
   );
   //SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "wobbly","road" }) );
   SetKeyName("sign");
   SetPreventGet("The sign obstinately refuses to budge.");
}

