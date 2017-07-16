#include <lib.h>
#include "../camp.h"

inherit LIB_ITEM;
 
static void create() {
    item::create();
    SetKeyName("bonfire");
    SetId( ({ "bonfire" }) );
    SetAdjectives( ({ "large"}) );
    SetShort("a large bonfire");
    SetRadiantLight(25);
    SetLong("The bonfire is in the center of the "
                   "camp.  A large area around the bonfire "
                   "has been cleared to allow room for dancing "
                   "and gatherings.");
    SetInvis(1);
    SetPreventGet("You can not pick up a fire.  It would burn you!"); 
    SetMass(20);
    SetValue(0);
       }
