#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName("brown deer pelt");
   SetShort("a brown deer pelt");
   SetId( ({ "pelt" }) );
   SetAdjectives( ({ "brown","deer" }) );
   SetLong("The pelt is soft and gentle.  Its leather hide is fairly "
           "tough, however.");
   SetMass(200);
   SetValue(30);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(250);
   SetProtection(SLASH,4);
   SetProtection(BLUNT,3);
   SetProtection(PIERCE,4);
   SetProtection(COLD,3);
   SetMaterial( ({ "natural","leather" }) );
  SetWarmth(20);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
