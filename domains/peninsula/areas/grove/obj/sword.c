#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sword");
  SetShort("a rusted shortsword");
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({ "short", "rusted" }) );
  SetLong("This shortsword has seen better days. It is rusted "
          "nearly to ruin and almost worthless. However, it is "
          "better than no sword at all.");
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(14);
  SetDamagePoints(1000);
  SetVendorType(VT_WEAPON);
  SetValue(10);
  SetMaterial("metal");
  SetRepairDifficulty(90);
}
