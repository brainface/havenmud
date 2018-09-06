#include <lib.h>
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("a large wooden sign");
   SetLong("The large wooden sign has been nailed into the ground.");
   SetRead("default", "The Twitchy Nymph Coffeehouse.\n"
     "North: Soleil.\n"
     "East: Sactum, Haven, Havenwood.\n",
     "West: Kresh, Karak, Lloryk.\n",
   );
   SetId( ({"sign"}) );
  SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "large","wooden" }) );
   SetKeyName("sign");
   SetPreventGet("The sign post is imbedded to deep in the ground to get "
                 "it out.");
}

//
