//Mahkefel@Haven
//burlap sack for kobolds

#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_STORAGE;

static void create()
{
  ::create();
  SetKeyName("sack");
  SetId( ({ "sack" }) );
  SetAdjectives( ({ "burlap","small" }) );
  SetShort("a small burlap sack");
  SetLong(
    "This small sack is made from rough burlap. A leather "
    "strap would allow it to be worn over the shoulder "
    "of a smaller humanoid."
  );
  SetCanClose(1);
  SetClosed(1);
  SetMass(30);
  SetMaterials( ({ "textile" }) );
  SetMaxCarry(300);
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(10);
  SetValue(100);
  SetVendorType(VT_CLOTHING);
}

