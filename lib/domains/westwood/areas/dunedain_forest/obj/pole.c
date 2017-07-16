/*
 * Coded by Dunedain@Haven
 * 11 September 1997
 */
 
 
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("black pole");
  SetRepairDifficulty(12);
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "wood working" : 1,
  ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("a black wooden pole");
  SetId( ({ "pole" }) );
  SetAdjectives( ({ "black","wooden","wood","oaken","dark" }) );
  SetLong("This is a dark oaken pole made of sturdy material.  Great "
          "care was taken in its creation.");
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(8);
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetValue(225);
  SetDamagePoints(800);
}
 
 
/* Approved by Balishae on Thu Sep 11 14:07:19 1997. */
