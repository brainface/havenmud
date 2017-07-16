#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("grimy axe");
   SetShort("a grimy axe");
   SetId( ({ "axe" }) );
   SetAdjectives( ({ "grimy" }) );
   SetLong("A grimy, dull blade forms the shape and life of this "
           "axe, which appears to be slowly falling apart.");
   SetMass(100);
   SetValue(100);
   SetDamagePoints(500);
   SetVendorType(VT_WEAPON);
   SetWeaponType("hack");
   SetDamageType(SLASH);
   SetClass(8);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(17);
   SetRepairSkills( ([
                       "weapon smithing" : 4,
                       "metal working" : 4,
                  ]) );
   call_out( (: eventReceiveDamage, 0, 1, 650 :), 0);
   SetHands(2);
   SetProperty("history","The axe fell into its degrading state "
               "by being held by Darken Scarzam, a dreadful zombie "
               "of Vale Castle.");
}