#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("sword");
   SetShort("Rummin's Sword");
   SetId(({ "sword" }) );
   SetAdjectives( ({ "rummin's" }) );
   SetLong("The name Rummin is engraved on the hilt, along with "
           "small symbols representing faith, strength, charity, "
           "and justice.  The blade is iron, and the hilt is "
           "coated in a thin sheathe of gold.");
   SetMass(50);
   SetValue(600);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(300);
   SetWeaponType("slash");
   SetDamageType(SLASH);
//   SetMaterial( ({ "metal" }) );
//   SetRepairDifficulty(20);
//   SetRepairSkills( ([
//                       "metal working" : 1,
//                       "weapon smithing" : 1,
//                  ]) );
   SetProperty("history","This sword belongs to Rummin, the Registrar of "
               "Averath.");
   SetClass(20);
}
