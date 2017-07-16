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
     "and just dangles through the opening of the chasm.");
   SetMass(1);
   SetValue(9999);
   SetMaterial("natural");
   SetDamagePoints(9999999);
   SetClimb("/domains/westwood/virtual/westwood/26,25", CLIMB_UP);
   SetPreventGet("It's firmly attached to something above.");
   SetInvis(1);
}
