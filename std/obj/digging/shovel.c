/*    /domains/Ylsrim/etc/shovel.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 951030
 */

#include <lib.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
    item::create();
    digging::create();
    SetKeyName("shovel");
    SetId("shovel", "spade");
    SetAdjectives( ({ "wooden" }) );
    SetShort("a shovel");
  SetMaterials( ({ "wood" }) );
    SetLong("A plain, wooden shovel.  You probably can dig things with "
	    "it.");
    SetMass(87);
    SetValue(50);
    SetProperty("farming item", 1);
  SetDamagePoints(100);
  SetClass(5);
}
