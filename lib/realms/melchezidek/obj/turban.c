

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
  SetKeyName("turban");
  SetId(( { "turban", "white turban", "cloth turban", 
    "white cloth turban" } ));
  SetShort("a white turban");
  SetLong("A neatly wrapped white cloth which sits upon"
  " the head, this turban works to protect the"
  " head of the wearer from the merciless sun of"
  " the desert. The cloth is soft and unblemished"
  " and appears to have been wrapped by a master.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
