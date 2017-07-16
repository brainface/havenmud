// by Dahaka
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("face mask");
  SetId( ({"mask"}) );
  SetAdjectives( ({"metal", "face"}) );
  SetShort("a metal face mask");
  SetLong(
    "This metal face mask looks very differant than the "
    "average helmet. This mask protects the face more "
    "than the rest of the head, giving the user fine "
    "protection on the face, but nothing else. Small "
    "leather bands rap around the user's head, keeping "
    "it on firm. "
    );
  SetArmourType(A_HELMET);
  SetValue(150);
  SetMass(120);
  SetClass(15);
  SetDamagePoints(1100);
  SetArmourClass(ARMOUR_PLATE);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(24);
  SetRepairSkills( ([
     "armour smithing" : 15,
     "metal working"   : 15,
     ]) );
  SetMaterial( ({"metal"}) );
  SetSize(SIZE_MEDIUM);
}