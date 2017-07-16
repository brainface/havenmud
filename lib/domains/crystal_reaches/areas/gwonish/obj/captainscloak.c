
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("captains cloak");
  SetId(( { "cloak", "leather cloak","captains cloak", 
            "captain's cloak"}));
  SetShort("leather cloak");
  SetLong("The full-length black leather cloak bears a captain's rank "
          "insignia on its collar.");
  SetDamagePoints((450+(random(3)*100)));
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({"leather"}) );
  SetWarmth(35);
  SetRepairSkills( ([
                     "leather working" : 2,
                 ]) );
  SetRepairDifficulty(12);
  SetMass(400);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(650);
  SetArmourType(A_CLOAK);
  
  // SetProtection(BLUNT,1);
  // SetProtection(SLASH,5);
  // SetProtection(PIERCE,4);
  // SetProtection(HEAT,2);
  // SetProtection(COLD,4);
  // SetProtection(MAGIC,1);
  // SetProtection(SHOCK,2);
}
