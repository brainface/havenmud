#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("leather pants");
   SetSize(SIZE_SMALL);
   SetShort("a pair of leather pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "leather","pair of" }) );
   SetLong("The leather pants are brown and made of a thin, soft "
           "leather.");
   SetMass(65);
   SetValue(90);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetDamagePoints(300);
   SetProtection(SLASH,3);
   SetProtection(BLUNT,2);
   SetProtection(PIERCE,4);
   SetProtection(COLD,2);
   SetProtection(HEAT,1);
   SetProtection(ACID,1);
   SetProtection(WATER,1);
   SetMaterial( ({ "leather" }) );
  SetWarmth(20);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "leather working" : 2,
                       "armour smithing" : 1,
                  ]) );
}
