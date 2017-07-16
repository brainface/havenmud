
/*  A small drum coded by Syra@Haven  */
/*modified by Xera@Haven*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("drum");
  SetShort("a small drum");
  SetId( ({ "drum", "bard_instrument" }) );
  SetAdjectives( ({ "small" }) );
  SetLong("The small drum has a tanned hide "
       "stretched over a wooden frame.  The "
       "wooden frame has been painted orange.");
  SetVendorType(VT_INSTRUMENT);
  SetValue(400);
  SetMass(5);
  SetMaterials( ({"wood","leather" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([ "wood working" : 1, 
                      "instrumental music" : 1, 
                      "leather working" : 2 ]) );
  SetDamagePoints(250);
  SetDamageType(BLUNT);
 }
