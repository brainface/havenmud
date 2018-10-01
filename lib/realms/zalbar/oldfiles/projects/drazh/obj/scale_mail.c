// modified by Dahaka
// Aug 2004

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("mail shirt");
    SetId( ({"armour", "shirt","mail shirt"}) );
    SetAdjectives( ({ "scale mail","scale" }) );
    SetShort("a scale mail shirt");
    SetLong(
      "This shirt is made of red and black scales which represents "
      "the Soirin religion. This scale mail shirt looks like it was "
      "well made for the wearer to survive a few battles.");
    SetVendorType(VT_ARMOUR);
    SetMass(325);
    SetMaterial("metal");
    SetSize(SIZE_MEDIUM);
    SetWarmth(0);
    SetValue(380);
    SetDamagePoints(750);
    SetArmourClass(ARMOUR_CHAIN);
    SetRestrictLimbs( ({ 
      "torso", "right arm", "left arm" 
      }) );
    SetArmourType(A_ARMOUR);
  }
