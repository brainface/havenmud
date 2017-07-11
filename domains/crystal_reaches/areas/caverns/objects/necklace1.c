/*  Necklace - Old Hag - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h> 
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("old hag's necklace");
  SetId( ({ "old hag's necklace", "hag's necklace", "necklace" }) );
  SetAdjectives( ({ "unique" }) );
  SetShort("the old hag's necklace");

  SetLong(
    "The old hag's necklace is unique in many ways. First of all the "
    "chain is made from a lightweight yet strong silvery metal, and the "
    "gem seems to be a rare one, a semiclear silverish tinted stone."
  );
  SetVendorType(VT_TREASURE|VT_ARMOUR);
  SetArmourType(A_AMULET);
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(10);
  SetValue(500);
  SetDamagePoints(300);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairSkills( ([ "mithril working"  :  10,
  ]) );
  SetRepairDifficulty(35);
}
