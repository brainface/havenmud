#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
 ::create();
 SetKeyName("knife");
 SetShort("a long knife");
 SetId( ({ "knife" }) );
 SetAdjectives( ({ "long" }) );
 SetLong(
   "The blade of this knife is nearly ten inches long. The "
   "hilt of the knife is simple with a leather grip. This "
   "knife looks extremely durable."
 );
 SetMaterial( ({ "metal" }) );
 SetRepairSkills( ([
   "metal working" : 1,
   "weapon smithing" : 1,
 ]) );
 SetRepairDifficulty(6);
 SetDamagePoints(600);
 SetClass(10);
 SetWeaponType("knife");
 SetDamageType(SLASH);
 SetVendorType(VT_WEAPON);
 SetValue(100);
 SetMass(30);
 }

/** Approved by Laoise at Wed Jul 14 22:11:42 2004. **/