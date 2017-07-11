/*  A staff for apprentices */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("stone staff");
  SetShort("a black stone staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "black", "stone" }) );
  SetLong("This black stone staff is heavy, made from something "
          "extra-worldly, and would obviously be an excellent weapon.");
  SetClass(25);
  SetMass(200);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(45);
  SetValue(9000);
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
