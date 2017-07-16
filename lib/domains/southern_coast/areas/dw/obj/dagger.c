/*  A dagger for the vampire */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("dagger");
  SetShort("an expensive looking dagger");
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(10);
  SetDamagePoints(900);
  SetClass(11);
  SetMass(40);
  SetLong("This jewelled dagger seems to be a family heirloom of "
          "a family long departed. Its timeless edge seems to "
          "have been honed to an extremely sharp razor-like "
          "quality over the years.");
  SetWield("The dagger feels perfectly balanced.");
  SetWeaponType("knife");
  SetValue(300);
  SetDamageType(PIERCE|SLASH);
  SetVendorType(VT_WEAPON);
  }
