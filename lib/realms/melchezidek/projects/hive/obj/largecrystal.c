#include <lib.h>
#include "../hive.h"

inherit LIB_ITEM;
 
static void create() {
   ::create();
   SetKeyName("cystal");
   SetId( ({ "crystal" }) );
   SetAdjectives( ({ "huge", "radiant", "green", "piece of" }) );
   SetShort("a huge radiant piece of green crystal");
   SetRadiantLight(50);
   SetLong("This is a monsterous green luminescent crystal. It is much"
           " larger in size, and most assuredly weight, than the average"
           " human.");
   SetMass(500);
   SetValue(0);
   SetMaterial("natural");
}
