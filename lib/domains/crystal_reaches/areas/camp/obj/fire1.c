#include <lib.h>
#include "../camp.h"

inherit LIB_ITEM;
 
static void create() {
    item::create();
    SetKeyName("campfire");
    SetId( ({ "campfire" }) );
    SetAdjectives( ({"small"}) );
    SetShort("a small campfire");
    SetRadiantLight(20);
    SetLong("The small campfire is used to provide light "
                   "and heat meals.");
    SetInvis(1);
    SetPreventGet("You can not pick up a fire.  It would burn you!"); 
    SetMass(10);
    SetValue(0);
 }
