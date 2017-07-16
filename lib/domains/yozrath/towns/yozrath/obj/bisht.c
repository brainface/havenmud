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
  SetKeyName("bisht");
  SetId(( { "bisht", "black bisht", "cloth bisht", 
    "black cloth bisht" } ));
  SetShort("a black cloth bisht");
  SetLong("The bisht is a traditional garment worn"
  " by the Desert Kylin men.  It is a thin,"
  " black woolen robe worn over the thobe."
  "  It is typically only worn by holy men,"
  " but on holy days and when visiting the"
  " Mosque all men are required to wear it.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}


