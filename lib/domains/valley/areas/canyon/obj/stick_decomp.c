#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("decomposing stick");
   SetShort("a decomposing stick");
   SetId( ({ "stick" }) );
   SetAdjectives( ({ "decomposing" }) );
   SetLong("Like most things left on the forest floor for a long time, "
           "this stick has begun to decompose slightly.");
   SetMass(5);
   SetValue(0);
   SetVendorType(VT_WEAPON);
   SetClass(2);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(110);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "wood working" : 1,
                  ]) );
   call_out( (: eventReceiveDamage, 0, BLUNT, 100 :), 0);
}


/* Approved by Zaxan on Sat Jan 17 02:49:06 1998. */
