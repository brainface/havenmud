#include <lib.h>
#include <climb.h> 
#include "../rook.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
static void create() {
   item::create();
   SetKeyName("rope");
   SetId( ({ "rope" }) );
   SetShort("a small length of rope");
   SetLong("This rope appears to be made of a silk.  It is smooth "
     "and just dangles down through the opening of the chasm.");
   SetMass(1);
   SetValue(9999);
   SetMaterial("natural");
   SetDamagePoints(9999999);
   SetClimb(R_ROOM + "lair8", CLIMB_DOWN);
   SetPreventGet("It's firmly attached to the rocks.");
   SetInvis(1);
}
