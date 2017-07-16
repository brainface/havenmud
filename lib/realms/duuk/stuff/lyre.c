/*  A lyre */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("lyre");
  SetShort("a finely tuned lyre");
  SetId( ({ "lyre", "bard_instrument" }) );
  SetAdjectives( ({ "finely", "tuned" }) );
  SetLong("This is a finely tuned lyre, an instrument "
          "resembling a medieval guitar.  It has 6 strings "
          "attached to a hollowed out wooden body. It has a "
          "deep and moving tone if played in the right hands.");
  SetVendorType(VT_INSTRUMENT);
  SetValue(1000);
  SetMass(200);
  SetMaterials( ({
    "wood" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([ "wood working" : 1, "instrumental music" : 1 ]) );
  SetDamagePoints(300);
  SetWeaponType("hack");
  SetDamageType(BLUNT);
  SetProperty("history", "This lyre was made in Haven Town.");
 }
