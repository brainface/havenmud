
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("sock");
  SetShort("a thick wool sock");
  SetId( ({"sock"}) );
  SetAdjectives( ({"thick","wool"}) );
  SetLong(
    "One of a pair of socks, this is made of thick grey "
    "wool, with yellow thread sewn into the heal and toe. "
    "It looks quite warm and comfortable. ");
  SetMass(20);
  SetValue(100);
  SetDamagePoints(1000);
  SetMaterials( ({ "textile" }) );
  SetWarmth(15);
  SetArmourType(A_SOCK);
  SetRepairDifficulty(15);
}
