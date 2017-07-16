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
  SetKeyName("horned helmet");
  SetId( ({ "helm" }) );
  SetAdjectives( ({ "horned" }) );
  SetShort("a horned helm");
  SetLong(
    "This iron helmet covers the top of the head, and protects "
    "the face with a noseguard. A curved horn of some animal is "
    "set on each side of the helmet."
  );
  SetMass(100);
  SetValue(2700);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CHAIN);
  SetDamagePoints(27000);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetMaterial( ({ "metal", "natural" }) );
  SetWarmth(0);
  SetRepairDifficulty(20);
}

