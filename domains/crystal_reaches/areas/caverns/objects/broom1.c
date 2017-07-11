/*  Broom - Old Hag - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("broom");
  SetId( ({ "broom" }) );
  SetAdjectives( ({ "ordinary" }) );
  SetShort("a broom");

  SetLong("This is an ordinary broom all the way from it's wooden handle, down "
          "to it's straw bristles.");

  SetMass(60);
  SetValue(20);
  SetDamagePoints(100);

  SetVendorType(VT_WEAPON);
  SetMaterial("wood");
  SetRepairDifficulty(5);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(8);
}