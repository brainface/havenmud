#include <armour_types.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetKeyName("helmet");
    SetId( ({ "helmet"}) );
    SetAdjectives( ({ "daemonic", "daemon","bone" }) );
    SetShort("a daemonic bone helmet");
    SetWarmth(2);
    SetLong(
      "This helmet is made from the skull of a daemon. The inside of the "
      "of the skull has has been padded for comfort and warmth. There is "
      "a large curled horn on each side of skull.");
    SetMaterial( ({ "natural" }) );
    SetRepairSkills( ([
          "natural working" : 20,
          "armour smithing" : 20,
          ]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_NATURAL);
    SetDamagePoints(1500);
    SetMass(200);
    SetArmourType(A_HELMET);
    SetSize(SIZE_MEDIUM);
    SetValue(1000);
}
