#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("an instructive sign");
   SetRead("default",
     "\n"
     "OOC: Hello crafty friends!\n"
     "These fields produce fabricy crops, in endless amounts. This "
     "is a convenience until such a day farming shows more depth, "
     "at which point these fields may mysteriously go away!"
     "\n"
   );

   SetLong(
     "A well-carved wooden sign is planted in the ground here. "
     "Carefully stenciled painted letters read the following: "
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "instructive" }) );
   SetKeyName("sign");
   SetPreventGet("The sign is securely moored in the ground.");
}

