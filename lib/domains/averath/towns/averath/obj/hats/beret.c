#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("beret");
  SetShort("a green beret");
  SetId( ({ "beret" }) );
  SetAdjectives( ({ "green" }) );
  SetLong("This small hat is rather dashing, and would look good on the head "
    			"of either sex. It is soft and round, made wool felt, and has a flat "
    			"crown.");  
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(200);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
