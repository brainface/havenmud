#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("long white glove");
   SetShort("a long white glove");
   SetId( ({ "glove" }) );
   SetAdjectives( ({ "long","white" }) );
   SetLong("This is a long white glove, just like one a "
           "fine lady would wear.  There are even little buttons "
           "at the end.");
   SetMass(6);
   SetValue(7);
   SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_LONG_GLOVE);
   SetDamagePoints(115);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}
