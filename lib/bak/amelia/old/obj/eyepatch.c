#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("eyepatch");
   SetShort("an eyepatch");
   SetId( ({ "eyepatch","patch" }) );
   SetLong("This simple black piece of leather was made to cover "
           "someone's missing eye up.  Eye sockets are not "
           "pleasant to stare at, so some owner kindly decided "
           "to wear this.");
   SetMass(1);
   SetValue(10);
   SetClass(10,9);
   SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_HELMET);
   SetDamagePoints(20);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
}
