//Alex@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create(){
  ::create();
  SetKeyName("leafsandals");
  SetId( ({"shoes", "sandals" }) );
  SetAdjectives( ({"leaf", "leafy", "woven"}) );
  SetShort("a pair of woven sandals");
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({"natural"}) );
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
  SetRepairDifficulty(5);
  SetWarmth(10);
  SetValue(3);
  SetLong(
    "These battered sandals seem to be woven from some "
    "kind of jungle fronds, and look more comfortable than "
    "warm.");
  SetSmell( "The sandals smell like feet." );
}
