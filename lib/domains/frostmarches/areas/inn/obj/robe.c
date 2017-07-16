#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("robe");
  SetId(( { "robe", "blue robe" } ));
  SetShort("a blue robe");
  SetLong("This is a blue magician's robe with many magical symbols printed "
          "on it.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  // SetProtection(PIERCE,2);
  // SetProtection(SLASH,2);
  // SetProtection(COLD,3);
  // SetProtection(MAGIC,3);
  // SetProtection(ACID,2);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("A small wave of magic passes over you as you wear the robe.");
}
