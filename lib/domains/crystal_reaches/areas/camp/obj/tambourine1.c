
/*  A small drum coded by Syra@Haven  */
/*modified by Xera@Haven to fit a tambourine*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("tambourine");
  SetShort("a small tambourine");
  SetId( ({ "tambourine", "bard_instrument" }) );
  SetAdjectives( ({ "small" }) );
  SetLong("The small tambourine has small "
       "tin discs set in a circular wood frame. ");
  SetVendorType(VT_INSTRUMENT);
  SetValue(50);
  SetMass(5);
  SetMaterials( ({"wood","metal" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([ "wood working" : 1, 
                      "instrumental music" : 1, 
                      "metal working" : 1 ]) );
  SetDamagePoints(50);
  SetWeaponType("hack");
  SetDamageType(BLUNT);
 }
