#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("spike");
   SetShort("a long stone spike");
   SetId( ({ "spike" }) );
   SetAdjectives( ({ "long", "stone" }) );
   SetLong("This long stone spike was carved from a black rock. It appears that"
           " the sole purpose of this weapon is to stab an enemy in vital points in"
           " order to debilitate or cause excessive bleeding.");
   SetMass(150);
   SetValue(800);
   SetDamagePoints(1000);
   SetVendorType(VT_WEAPON);
   SetWeaponType("pierce");
   SetDamageType(PIERCE);
   SetClass(22);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "weapon smithing" : 8,
                       "natural working" : 8,
                  ]) );
}
