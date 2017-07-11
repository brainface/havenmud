// Zeratul@Haven 11/04/2001
// for necro leader

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("kris");
  SetShort("a long, bloodstained kris");
  SetId( ({ "kris","long kris" }) );
  SetAdjectives( ({ "long","bloodstained" }) );
  SetLong(
     "This unique weapon is a dagger with a ridged serpentine blade. The tip of the "
     "weapon is covered with recently dried blood, showing signs of recent use. "
  );
  SetMass(25);
  SetValue(600);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetWeaponType("knife");
  SetDamageType(PIERCE|SLASH);
//  SetMaterial( ({ "metal" }) );
//  SetRepairDifficulty(40);
//  SetRepairSkills( ([
//     "weapon smithing" : 5,
//     "metal working" : 5,
//  ]) );
  SetClass(35);
  SetProperty(
     "magic","This weapon has a strange aura about it. It has been used for many "
     "necromantic rituals and might be considered cursed by some. ",
  );
  SetProperty(
     "history","This weapon was crafted to be used for sacrificial use, or to be "
     "used to take down ones enemies. ",
  );
}
