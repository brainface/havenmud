/*    /domains/Ylsrim/etc/shovel.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 951030
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
    item::create();
    digging::create();
    SetKeyName("laser-aided hammer");
    SetId( ({ "hammer" }) );
    SetAdjectives( ({ "laser", "aided" }) );
    SetShort("a laser-aided hammer");
    SetLong(
      "This large piece of equipment is used for heavy mining within the "
      "ore-fields of the various mining (and farming!) concerns of the galaxy."
      );
    SetMass(120);
    SetValue(50);
    SetProperty("farming item", 1);
    SetDamagePoints(1200);
    SetClass(10);
    SetWeaponType("melee");
    SetDamageType(BLUNT);
    SetVendorType(VT_MINING);
}
