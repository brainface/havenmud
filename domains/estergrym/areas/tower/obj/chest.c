// A chest, nothing more.

#include <lib.h>
#include "../defs.h"

inherit LIB_STORAGE;

static void create() {
    ::create();
    SetKeyName("chest");
    SetId( ({ "chest" }) );
    SetAdjectives( ({ "wooden", "large"}) );
    SetShort("a large wooden chest");
    SetLong("It is square with thin metal bracers along the corners. "
            "The wood that creates the box is in decent condition and "
            "it is polished with a slight shine to its surface. The inside "
            "of the chest has some ink along the corners of the chest "
            "and contains some dents on the inside as well. The lid is "
            "hollow on the inside for slightly more storage room.");
    SetMass(45);
    SetCanClose(1);
    SetPreventGet("It is sealed to the ground!");
    SetMaxCarry(350);
    SetInventory( ([ 
	                TOWER_OBJ "wood" : 3,
					]) );

}