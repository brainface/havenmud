#include <lib.h>
#include "../hive.h"

inherit LIB_ITEM;
 
static void create() {
   ::create();
   SetKeyName("cystal");
   SetId( ({ "crystal" }) );
   SetAdjectives( ({ "small", "radiant", "green", "piece of" }) );
   SetShort("a small radiant piece of green crystal");
   SetRadiantLight(15);
   SetLong("This is a small piece of green crystal that gives off"
           " a light green luminescence providing a small amount of light.");
   SetMass(3);
   SetValue(0);
   SetMaterial("natural");
}
