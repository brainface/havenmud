#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;


static void create() 
{
  armour::create();
  SetKeyName("black boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "black", "leather", "thick"}) );
  SetShort("a pair of thick black leather boots");
  SetLong("Course thick leather has been crafted into sturdy boots.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetProperty("multiples", 1);
  SetValue(80);
  SetDamagePoints(2500);
  // SetProtection(BLUNT, 8);
  // SetProtection(PIERCE, 14);
  // SetProtection(SLASH, 15);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetRepairSkills( ([
                     "leather working" : 6,
                 ]) );
  SetRepairDifficulty(10);
}
