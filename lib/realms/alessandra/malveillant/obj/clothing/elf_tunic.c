/*  Portia  RUINS  10-7-98
   A tunic for a dark elf.
*/

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tunic");
  SetShort("a leather tunic");
  SetId( ({"tunic"}) );
  SetAdjectives( ({"leather", "soft"}) );
  SetLong("This leather tunic is cut very nicely and sewn by a skilled "
          "hand. The leather is incredibly soft to the touch.");
  SetMass(40);
  SetValue(40);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather"}) );
  SetWarmth(10);
  SetRepairSkills( ([
         "leather working" : 5,
              ]) );
  SetRepairDifficulty(8);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  SetDamagePoints(400);
  // SetProtection(HEAT, 4);
  // SetProtection(PIERCE, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(BLUNT, 5);
  }
/*   [ Portia approved ] */
