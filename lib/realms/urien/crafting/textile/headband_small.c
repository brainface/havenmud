//Illura@Haven, Aug 2011
//Linen Headband Size Small
#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("linen headband");
  SetShort("a white linen headband");
  SetId( ({"headband", "band"}) );
  SetAdjectives( ({ "linen", "white" }) );
  SetLong("This is a snowy white headband of clean linen. It flutters like a ribbon in the breeze, making the wearer look dashing and mysterious.");
  SetMass(5);
  SetValue(5);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_SMALL);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(30);
  SetClass(10);
  SetMaterial("textile");
  SetRepairSkills( (["textile working": 5,]) );
  SetRepairDifficulty(4);
}

