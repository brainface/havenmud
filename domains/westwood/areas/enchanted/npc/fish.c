// Amelia@Haven

#include <lib.h>
inherit LIB_FISH;
#include "balz.h"
 
static void create() {
    fish::create();
    SetKeyName("small fish");
    SetFood( B_OBJ + "/fishmeal");
    SetShort("a small fish");
    SetLong("This is a small, wriggling fish.");
    SetMass(15);
    SetId( ({ "small fish", "fish" }) );
}