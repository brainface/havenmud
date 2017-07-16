#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("solid pointed knife");
   SetShort("a solid pointed knife");
   SetId( ({ "knife","blade" }) );
   SetAdjectives( ({ "solid","pointed","pierce" }) );
   SetLong("As the knife tapers down to a point, the blade looses "
           "no strength and does not easily bend.  The edges are "
           "not really sharpened or made to be sharp, making it "
           "much more a pierce type of weapon than an actual knife.");
   SetClass(19);
   SetMass(200);
   SetVendorType(VT_WEAPON);
   SetValue(350);
   SetWeaponType("pierce");
   SetDamageType(PIERCE);
   SetDamagePoints(900);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(20);
   SetRepairSkills( ([
                       "metal working" : 4,
                       "weapon smithing" : 4,
                  ]) );
}

