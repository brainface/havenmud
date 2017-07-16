#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a simple knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "simple" }) );
   SetLong("This plain knife is made of a fairly strong metal "
           "and can be sharpened to a fine edge.  It has a "
           "leather handle that is easy to hold.");
   SetMass(10);
   SetValue(100);
   SetClass(13);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE|SLASH);
   SetDamagePoints(225);
   SetMaterial( ({ "leather","metal" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "leather working" : 0,
                       "metal working" : 1,
                       "weapon smithing" : 0,
                  ]) );
}

