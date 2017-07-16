//Alex@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create(){
  armour::create();
  SetKeyName("blue hat");
  SetId( ({"hat"}) );
  SetAdjectives( ({ "blue", "battered" }) );
  SetShort("a battered blue hat");
  SetLong(
    "This woven blue hat of jungle grasses covers most of the head "
    "while making the wearer look like someone's demented "
    "grandfather. Hopefully you got a cup of soup when you "
    "purchased it, too.");
  SetVendorType(VT_ARMOUR);
  SetMass(40);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(150);
  SetDamagePoints(250);
  SetRepairDifficulty(5);
  SetMaterial( ({"natural"}) );
  SetArmourType(A_HELMET);
  SetWarmth(3);
}
