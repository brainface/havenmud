#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("club");
   SetShort("a wooden club");
   SetId( ({ "club","log" }) );
   SetAdjectives( ({ "wooden","large","heavy" }) );
   SetLong("This large, heavy log serves as a basic club "
           "with a good deal of force behind it.  It hasn't "
           "been given the best of care, but could be repaired "
           "to a good condition.");
   SetMass(300);
   SetValue(30);
   SetClass(11);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(225);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
      "weapon smithing" : 0,
      "wood working" : 0,
      ]) );
   call_out( (: eventDeteriorate, 1 :), 1);
   SetProperty("history","An ogre weilded this club during a "
               "misguided battle against Soleil.");
}
