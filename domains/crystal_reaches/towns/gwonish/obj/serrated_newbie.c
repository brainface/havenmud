#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("serrated sword");
  SetShort("a poor quality serrated-edged sword");
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "serrated", "edged", "poor", "quality" }) );
  SetClass(16);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetValue(0);
  SetMass(160);
  SetLong("This sword is short with a serrated (v-edges line the "
          "blade) edge. The workmanship is poor and the quality "
          "isn't great."
          );
  SetDamagePoints(2000);
  SetMaterial("metal");
  SetRepairDifficulty(10);
}