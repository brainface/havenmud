
// Water Circlet
// Laoise
// May 2001

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    ::create();
    SetProperty("laoise_flag", 1);
    SetKeyName("water circlet");
    SetId( ({ "circlet" }) );
    SetAdjectives( ({ "water" }) );
    SetShort("a circlet formed of water");
    SetLong(
    "A circlet formed from the waters of the ocean, solidified into a form "
    "which can be worn atop the head. The material is cool to the touch "
    "and has faint movement within its depths as the salt water continues "
    "to flow and swirl inside of its confinement. A raised sigil adorns the "
    "crest of the circlet, appearing to be in the shape of a starfish."
    );
    SetWear("The water circlet curves and alters it shape as you "
    "slip it on, conforming to the shape of your brow and fitting "
    "snugly.");
    SetArmourType(A_HELMET);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_NATURAL);
    SetProtectionBonus(WATER, 20);
    SetMass(3);
    SetValue(80);
    SetDamagePoints(400);
    SetSize(SIZE_MEDIUM);
}
