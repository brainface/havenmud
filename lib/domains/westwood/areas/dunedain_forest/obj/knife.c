#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
 
 
static void create() {
   item::create();
   SetShort("a hunting knife");
   SetLong("This weapon is carried by many hunters "
           "for skinning their captured game.");
   SetId( ({"knife","weapon"}) );
   SetClass(8);
   SetDamagePoints(540);
   SetValue(95);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetKeyName("knife");
   SetMass(25);
   SetVendorType(VT_WEAPON);
   SetAdjectives( ({"hunting"}) );
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(7);
   SetRepairSkills( ([
      "metal working" : 0,
      "weapon smithing" : 1,
      ]) );
}
 
 
 
/* Approved by Balishae on Thu Sep 11 13:55:01 1997. */
