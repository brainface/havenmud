/*    /domains/Ylsrim/etc/chest.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 951028
 */

#include <lib.h>
#include <std.h>

inherit LIB_STORAGE;

static void create() {
    storage::create();
    SetKeyName("chest");
    SetId( ({ "chest" }) );
    SetAdjectives( ({ "wooden" }) );
    SetShort("a wooden chest");
    SetLong("This chest is made from an ancient forest far from "
	    "Ylsrim.  You can feel the age in touching it.");
    SetMass(1200);
    SetValue(300);
  AddInventory(STD_ARMOUR "shirt/chain", 1);
    SetCanClose(1);
    SetClosed(1);
    SetMaxCarry(2000);
}
