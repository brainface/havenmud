#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("axe");
    SetId( ({ "primitive axe", "crude axe", "axe" }) );
    SetShort("a primitive axe");
    SetLong("This crude weapon is nothing more than a flat, heavy rock "
    "lashed to a stout piece of wood with leather strips.  It's lack of "
    "refinement, however, has little effect on its ability to hack things.");
    SetValue(100);
    SetMass(180);
    SetMaterial( ({ "natural", "wood", }) );
    SetRepairSkills( ([
    "stone working" : 2,
    "leather working" : 2,
    "wood working" : 2,
    "weapon smithing" : 2,
    ]) );
    SetWeaponType("hack");
    SetDamageType(SLASH);
    SetDamagePoints(900);
    SetClass(13);
    SetHands(2);
}
