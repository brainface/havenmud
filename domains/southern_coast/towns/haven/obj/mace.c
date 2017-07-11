#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mace");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 1,
     "weapon smithing" : 3,
     ]) );
  SetShort("a heavy metal mace");
  SetAdjectives( ({ "heavy", "metal" }) );
  SetId( ({ "mace" }) );
  SetLong("This thick mace is of the type preferred by the Kylin Templars. "
          "Used in keeping the peace in Haven Town, it has a certain weight "
          "to it which can only be described as otherworldly.");
  SetClass(14);
  SetDamagePoints(1200);
  SetValue(180);
  SetMass(90);
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  }
