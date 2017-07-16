#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../forest.h"
inherit LIB_ITEM;
 
static void create()
{
item::create();
  SetKeyName("claw");
  SetId( ({ "claw" }) );
  SetAdjectives( ({ "sharp","bear" }) );
  SetShort("a bear claw");
  SetLong("The sharp nails on the ends of this bear claw may provide limited "
          "assistance in fighting an opponent.");
  SetMass(40);
  SetValue(20);
  SetDamagePoints(300);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetClass(4);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(99);
}


/* Approved by Balishae on Thu Sep 11 13:57:29 1997. */
