#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
  item::create();
  SetKeyName("spear");
  SetId( ({ "spear", }) );
  SetAdjectives( ({ "training" }) );
  SetShort("training spear");
  SetLong(
    "It is a sturdy four foot shaft of wood "
    "that comes to a sharp point. Nosferatu draw "
    "blood when they train their young. Only the "
    "survivors get to join the Grymxorian Army."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(30);
  SetValue(90);
  SetDamagePoints(1250);
  SetClass(6);
  SetMaterial("wood");
  SetRepairSkills( ([
    "weapon smithing" : 2,
    "wood working" : 2,
  ]) );
  SetRepairDifficulty(5);
}
