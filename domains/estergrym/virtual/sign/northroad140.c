#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a wobbly road sign");
   SetLong(
     "A rickety road sign leans to and fro with the wind here. "
     "Wooden arrows point off in various directions with abandon. "
   );
   SetRead("default",
     "West: Gurov, Keryth\n"
     "South: Grymxoria, the Port of Parva\n"
   );
   //SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "wobbly","road" }) );
   SetKeyName("sign");
   SetPreventGet("Wobbly as the sign's foundation is, it doesn't seem to "
     "be going anywhere.");
}

