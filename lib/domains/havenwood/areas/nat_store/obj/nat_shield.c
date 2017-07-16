#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("alligator shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "alligator","skin" }) );
    SetShort("an alligator skin shield");
    SetLong("This shield is made from the thick leather hide of an alligator "
      "head stretched across a wooden frame. The dense, scaley skin stops blows "
      "nearly as well as chainmail, at a fraction of the weight."
    );
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_NATURAL);
    SetSize(SIZE_MEDIUM);
    SetMass(300);
    SetValue(7500);
    SetDamagePoints(3000);
    SetProperty("multiples", 1);
    //SetRestrictLimbs( ({ "left arm", "left hand" }) );
    SetArmourType(A_SHIELD|A_WEAPON);
    SetMaterial( ({ "natural" }) );
    SetRepairDifficulty(70);
}
