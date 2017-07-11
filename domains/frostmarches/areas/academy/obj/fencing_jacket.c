/*
 pretty standard leather armour, in line with the vendor's armour
 it's small size though, and covers the left and right arm, which
 vendor armour doesn't cover.
 In other words, it's slightly useful to some players.
 */

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("fencing jacket");
  SetId( ({ "jacket" }) );
  SetAdjectives( ({ "leather","fencing"}) );
  SetShort("a fencing jacket");
  SetLong(
    "This jacket has been painted white, making the wearer "
    "easy to see on a dimly lit practice field. The solid leather "
    "hide along the chest and arms would provide some protection from "
    "blows of any sort, and the cotton lining would ward off some of "
    "the chill of the frostmarches. "
  );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_ARMOUR); //arms and torso
  SetDamagePoints(2500);
  SetMass(200);
  SetMaterial( ({ "leather" }) );
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_SMALL);
  SetWarmth(5);
  SetWear("The fencing jacket smells slightly of wet fur.");
  SetValue(250);
}

