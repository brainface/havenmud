//
// Summary: scale knife for krull
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 28/05/99
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("scale knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "shiny", "dragon", "scale" }) );
  SetShort("a shiny dragon scale knife");
  SetLong("This is a medium-sized knife made of sharpened dragon "
          "scales. The scales have been perfectly cut and sharpened "
          "in order to forge the knife, and seem to be joined together "
          "by an unknown force."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2900);
  SetClass(23);
  SetValue(1500);
  SetMass(400);
  SetWeaponType("knife");
  SetMaterial( ({"natural"}) );
  SetRepairSkills( ([
     "natural working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(PIERCE);
  SetProperty("history", "Long before the first GodsWar, a dragon "
                         "with the the hardest of scales was slayed "
                         "by a powerful knight who also was a skilled "
                         "smithy. After removing the skin from the "
                         "corpse, he gathered a few of its scales "
                         "and started working on them until "
                         "finally he forged this knife."
             );
}
