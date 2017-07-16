#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetRepairDifficulty(22);
  SetShort("a finely crafted longsword");
  SetRepairSkills( ([
    "metal working" : 3,
    "weapon smithing" : 3,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetLong("This is a weapon of great value and use.  It was obviously "
         "created with painstaking care.");
  SetId( ({ "longsword", "sword" }) );
  SetAdjectives( ({ "finely", "crafted" }) );
  SetVendorType(VT_WEAPON);
  SetValue(400);
  SetClass(13);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetDamagePoints(1500);
  SetMass(190);
 }
