/*  A staff for apprentices */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("marble staff");
  SetShort("a marble staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "marble" }) );
  SetLong("This marble staff is heavy, made from something "
          "extra-worldly, and would obviously be an excellent weapon.");
  SetClass(40);
  SetMass(250);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(55);
  SetValue(20000);
  SetWeaponType("pole");
  SetVendorType(VT_WEAPON);
  SetDamageType(MAGIC|COLD|BLUNT);
  SetWield("The coldness of the staff chills your hands.");
  SetProperty("history", "This staff comes from the Lamrani Temple, "
                         "in the first lower plane.");
  SetProperty("magic", "This staff inflicts magical and cold damage, "
                       "in addition to the weight of the weapon.");
  SetHands(2);
 }

