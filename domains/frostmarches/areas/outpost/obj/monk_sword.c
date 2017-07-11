#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("sword");
  SetId( ({ "sword"}) );
  SetAdjectives( ({"two", "handed", "executioner"}) );
  SetShort("a two-handed executioner sword");
  SetLong("The silver blade of this two-handed sword is flat with "
          "parallel edges and a blunt tip. The handle of this two-handed "
          "sword is long enough to ensure a good grip. Etched into the "
          "base of the blade is the Kylin symbol, a balance with a dragon "
          "entwined around it. This type of sword is called an "
          "executioner's sword and used by the Orthodox Kylin Monks.");
  SetMass(280);
  SetValue(1000);
  SetDamagePoints(2500);
  SetWeaponType("slash");
  SetDamageType(SLASH|BLUNT);
  SetClass(35);
  SetHands(2);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(50);
  SetVendorType(VT_WEAPON);
}

