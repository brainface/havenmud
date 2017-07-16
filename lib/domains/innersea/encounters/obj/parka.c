#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("parka");
  SetId( ({ "parka" }) );
  SetAdjectives( ({ "sealskin" }) );
  SetShort("a sealskin parka");
  SetLong(
    "This heavy parka is made of rubbery sealskin. Thick bundles of fur "
    "at the neck and hands insulate the extremities. It would protect the "
    "wearers torso and limbs in the harshest of environments."
  );
  SetMass(500);
  SetValue(1000);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_NATURAL);
  SetDamagePoints(8000);
  SetArmourType(A_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetMaterial( ({"natural" }) );
  SetWarmth(80);
  SetRepairDifficulty(20);
}

