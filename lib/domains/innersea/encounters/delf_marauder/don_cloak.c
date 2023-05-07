//  a badass cloak for a badass

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();

  SetKeyName("shadowy cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "shadowy", "black", "satin", "heavy" }) );
  SetShort("a shadowy cloak");
  SetLong(
     "Crafted from a heavy satin, this cloak is as black as midnight. "
     "It covers the wearer in shadow well, the only revealing characteristic "
     "being the soft sheen of the satin that gives the illusion of ripples "
     "in an endless dark sea."
     );
  SetWear("Shadows ripple around you.");
  SetMass(150);
  SetWarmth(10);
    SetValue(5000);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_CLOAK);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);

  // oh, oh, oh, it's magic
  SetRadiantLight(-20);
  SetProperty("history",
     "Handed down from father to piratey son over several generations, legend "
     "tells of a sea witch imbuing the cloak with the magic of darkness."
     );
  SetProperty("magic",
     "This cloak has been imbued with the power of darkness, making night "
     "what was once day."
     );
}
