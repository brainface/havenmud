#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("baleful mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "crude","carved","baleful","wooden","stained" }) );
  SetShort("a crudely carved mask");
  SetLong(
     "As if carved directly from the side of a tree, this mask is "
     "layered with dead and peeling bark. A broken and deformed branch "
     "protrudes in the place of a nose and the holes for the eyes and a "
     "mouth have been crudely carved out. A deep brownish-red stains "
     "the jagged mouth line giving the disturbing impression of blood-"
     "stained fangs." 
     );
  SetMass(150);
  SetValue(250);
  SetMaterial( ({ "wood" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetWarmth(5);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetSize(SIZE_LARGE);
  SetDamagePoints(2500);
}

