
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a well-crafted knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "well-crafted" }) );
   SetLong("This knife was made by a fine craftsman.  Its "
           "edge is easily sharpened by merchants of little "
           "skill.");
   SetMass(10);
   SetValue(105);
   SetClass(9);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetDamagePoints(300);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "weapon smithing" : 1,
                       "metal working" : 1,
                  ]) );
   SetProperty("history","This knife used to be the property of "
               "a citizen in Parva.");
}
