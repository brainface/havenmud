#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("plain knife");
   SetShort("a plain knife");
   SetId( ({ "knife" }) );
  SetAdjectives( ({ "plain" }) );
  SetLong(
    "This is a simple iron knife, which appears sturdy but not of the "
    "highest caliber. Deep grooves are etched in its handle to aid in "
    "grip for the wielder. A flat guard at the bottom of the blade prevents "
    "the hand from sliding upwards when stabbed in to something. "
    "The blade is dull but smooth, curving sharply from the straight sides "
    "in to a sharp point."
  );
   SetClass(12);
   SetMass(150);
   SetVendorType(VT_WEAPON);
   SetValue(150);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(650);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "metal working" : 2,
                       "weapon smithing" : 2,
                  ]) );
}
