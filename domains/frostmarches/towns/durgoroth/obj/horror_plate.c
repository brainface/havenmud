
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("suit");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of daemonic heavy platemail");
  SetLong("This suit of heavy platemail was made especially"
          " for horrors of Durgoroth. The daemon's"
          " blood and sweat, as well as the blood of"
          " others, cover it from top to bottom.");
  SetValue(5000);
  SetMass(300);
  SetWarmth(0);
  SetSize(SIZE_LARGE);
  SetDamagePoints(3000);
  SetId( ({ "suit", "platemail", "plate" }) );
  SetAdjectives( ({ "daemonic", "daemon", "heavy"}) );
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
 }

