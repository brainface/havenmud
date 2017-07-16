#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../forest.h"
inherit LIB_ITEM;
 
static void create()
{
item::create();
  SetKeyName("beak");
  SetId( ({ "beak" }) );
  SetAdjectives( ({ "owl" }) );
  SetShort("an owl beak");
  SetLong("This beak was once part of an owl.  Its sharp tip could be used "
          "to scratch an enemy.");
  SetMass(30);
  SetValue(15);
  SetDamagePoints(250);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(4);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(60);
}


/* Approved by Balishae on Thu Sep 11 13:57:25 1997. */
