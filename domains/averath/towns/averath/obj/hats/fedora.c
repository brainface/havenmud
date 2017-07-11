#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("fedora");
  SetShort("a grey fedora");
  SetId( ({ "fedora" }) );
  SetAdjectives( ({ "grey" }) );
  SetLong("This hat looks very attractive. It is creased lengthwise down the "
    			"crown and pinched in the front on both sides.");  
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(400);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
