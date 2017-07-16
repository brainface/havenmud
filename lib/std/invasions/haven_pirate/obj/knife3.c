#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a decorative knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "decorative" }) );
   SetLong("This decorative knife can still be sharpened to a "
           "fine edge like any good knife, but it also has "
           "some nice designs in the handle.  It appears "
           "to be very well crafted.");
   SetMass(13);
   SetValue(400);
   SetClass(17);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE|SLASH);
   SetDamagePoints(425);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "weapon smithing" : 0,
                       "metal working" : 1,
                  ]) );
}

