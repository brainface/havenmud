/*  A small drum coded by Syra@Haven  */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("drum");
  SetShort("a small drum");
  SetId( ({ "drum", "bard_instrument" }) );
  SetAdjectives( ({ "small" }) );
  SetLong("This small drum is very sturdy. It was "
          "obviously made by an expert, as the hide has "
          "been stretched perfectly over the bent "
          "wooden frame, so as to produce the same "
          "sharp sound no matter where it's struck.");
  SetVendorType(VT_INSTRUMENT);
  SetValue(700);
  SetMass(5);
  SetMaterials( ({"wood","leather" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([ "wood working" : 1, 
		      "instrumental music" : 1, 
                      "leather working" : 2 ]) );
  SetDamagePoints(500);
  SetWeaponType("hack");
  SetDamageType(BLUNT);
  SetProperty("history", "This drum was made in West Wood.");
 }

