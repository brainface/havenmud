// jungle-10,8

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
     "North: the Ruins of Durgoroth, Old Arcanith, Keryth,\n"
     "East: Jidoor, Glimmerdin, Unghk,\n"
     "South: Baria."
   );
   //SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "wobbly","road" }) );
   SetKeyName("sign");
   SetPreventGet("Wobbly as the sign's foundation is, it doesn't seem to "
     "be going anywhere.");
}

