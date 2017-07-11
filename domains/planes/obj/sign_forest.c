#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sign");
   SetShort("an important warning sign");
   SetId( ({ "sign","warning" }) );
   SetAdjectives( ({ "warning","important" }) );
   SetLong("The warning sign is suspended in the air above the hole.  "
           "It looks very important.  It would probably be a very "
           "good idea to <read sign>.");
   SetRead("default","The important warning sign reads:\n"
           "WARNING:  The Twisted Forest Planes\n"
           "surrounds you.  Smart beings should\n"
           "leave now by entering the hole.");
   SetPreventGet("The sign resists your efforts to take it.");
   SetProperty("magic","Part of the magic of the Twisted Forest keeps "
               "the sign in its place.");
   SetMaterial("wood");
}
