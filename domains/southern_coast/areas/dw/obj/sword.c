/*  A sword for the skeletons */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("longsword");
  SetShort("a servicable longsword");
  SetId( ({ "longsword", "sword" }) );
  SetAdjectives( ({ "servicable" }) );
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(10);
  SetValue(25);
  SetMass(40);
  SetClass(14);
  SetDamagePoints(500);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetLong("This longsword appears to have had better days, but "
          "still would work fine as a weapon.");
 }
