#include <lib.h>
#include <climb.h>
#include "../minaret.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
   item::create();
   SetShort("a long hemp rope");
   SetLong("The rope dangles from the higher path of the minaret.");
   SetId( ({"rope"}) );
  SetClimb(
    MIN_ROOMS "/path23t1", CLIMB_DOWN,
  );
  SetClimb( MIN_ROOMS "/path0t3", CLIMB_UP);
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "long","hemp" }) );
   SetKeyName("rope");
   SetPreventGet("The rope is secured to the upper ledge.");
}
