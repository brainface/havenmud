// Torak 8/12/2013

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("chigiriki");
  SetShort("a chitinous chigiriki");
  SetId( ({ "chigirki" }) );
  SetAdjectives( ({ "chitinous" }) );
  SetLong(
    "A short chitinous staff with a metal chain at the top "
    "connecting to a spiked chitinous weight at the end."
  );
  SetWeaponType("melee");
  SetDamageType(BLUNT|PIERCE);
  SetVendorType(VT_WEAPON);
  SetClass(30);
  SetDamagePoints(3000);
  SetValue(random(500)+800);
  SetMass(100);
  SetMaterial("natural");
  SetRepairSkills( ([
     "metal working" : 30,
     "natural working" : 30,
     "weapon smithing" : 30,
    ]) );
  SetHands(1);
  SetRepairDifficulty(20);
}
