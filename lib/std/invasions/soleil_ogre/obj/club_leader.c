#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("club");
   SetShort("a giant wooden club");
   SetId( ({ "club","log" }) );
   SetAdjectives( ({ "giant","wooden","large","heavy" }) );
   SetLong("This huge wooden club is massive in weight and "
           "solid; it would cause a lot of damage, if someone "
           "had the strenght to weild it with ease.");
   SetMass(500);
   SetValue(40);
   SetClass(17);
   SetVendorType(VT_WEAPON);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(325);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
      "weapon smithing" : 0,
      "wood working" : 0,
      ]) );
   SetProperty("history","An Urgesh shaman weilded this "
               "massive club during battle which he led "
               "against Soleil.  The ogre had great strength.");
}
