#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("plain longbow");
   SetShort("a plain longbow");
   SetId( ({ "longbow","bow" }) );
   SetAdjectives( ({ "plain","long" }) );
   SetLong("The bow is simple and unadorned, with little special about "
           "it.  It is, however, well-made with proper and good "
           "materials.");
   SetMass(100);
   SetValue(120);
   SetVendorType(VT_WEAPON);
   SetWeaponType("projectile");
   SetDamageType(PIERCE);
   SetDamagePoints(460);
   SetClass(14);
   SetMaterial( ({ "wood","natural" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "wood working" : 1,
                       "natural working" : 1,
                       "weapon smithing" : 1,
                  ]) );
}
