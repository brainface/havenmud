#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("pointed spear");
   SetShort("a pointed spear");
   SetId( ({ "spear" }) );
   SetAdjectives( ({ "pointed","sharp","long" }) ); 
   SetLong("A sharp point is attached to the long shaft of this spear.");
   SetMass(115);
   SetValue(1020);
   SetClass(16);
   SetWeaponType("pole");
   SetDamageType(PIERCE);
   SetDamagePoints(450);
   SetVendorType(VT_WEAPON);
   SetHands(2);
   SetMaterial( ({ "wood","metal" }) );
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "wood working" : 2,
                       "metal working" : 1,
                       "weapon smithing" : 2,
                  ]) );
}
