/* Portia  10-14-98
    Pants for the guards.
*/

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetShort("a pair of leather pants");
  SetId( ({"pants"}) );
  SetAdjectives( ({"leather"}) );
  SetLong("These leather pants are made of the finest leather and "
          "look like they may offer great protection.");
  SetValue(80);
  SetMass(80);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetMaterial( ({"leather"}) );
  SetWarmth(20);
  SetRepairSkills( ([
         "leather working" : 7,
      ]) );
  SetRepairDifficulty(30);
  SetArmourType(A_PANTS);
  SetVendorType(VT_ARMOUR);
  // SetProtection(SLASH,4);
  // SetProtection(PIERCE,4);
  // SetProtection(BLUNT,4);
  }
