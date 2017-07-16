// Artanis@Haven (August 11, 2004)

#include <damage_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("tekken");
  SetId( ({ "tekken" }) );
  SetAdjectives( ({ "spiked" }) );
  SetShort("a spiked tekken");
  SetLong(
     "This weapon is a grouping of metal that forms around the "
     "user's fist. It forms around the four fingers, while leaving "
     "the thumb position exposed. Spikes protrude out from each finger, "
     "giving the knuckle formed glove an added punch. "
  );
  SetClass(17);
  SetDamagePoints(1800);
  SetMass(75);
  SetWeaponType("melee");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetValue(450);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 2,
     "weapon smithing" : 2,
  ]) );
  SetRepairDifficulty(15);
  SetProperty("history",
              "This weapon was forged in the smithies of Tai-Ri."
  );
}
