#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("light axe");
   SetShort("a light axe");
   SetId( ({ "axe" }) );
   SetAdjectives( ({ "light" }) );
   SetLong("A sharp, shiny blade caps off this axe, which appears to "
           "be much lighter than others of the same size and class.");
   SetMass(100);
   SetValue(1020);
   SetDamagePoints(950);
   SetVendorType(VT_WEAPON);
   SetWeaponType("hack");
   SetDamageType(SLASH);
   SetClass(13);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "weapon smithing" : 3,
                       "metal working" : 3,
                  ]) );
}
