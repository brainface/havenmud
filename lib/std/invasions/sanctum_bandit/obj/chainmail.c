/*  Chainmail for bandit invasion
 */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chainmail suit");
  SetShort("a suit of chainmail");
  SetId( ({ "chainmail", "suit", "armour", }) );
  SetAdjectives( ({ "of", "chainmail" }) );
  SetLong(
    "This chainmail armour is a fine build and make."
  );
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(800);
  SetArmourClass(ARMOUR_CHAIN);
  SetValue(80);
  SetMass(120);
  SetArmourType(A_BODY_ARMOUR);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetSize(SIZE_MEDIUM);
  }
