/*  Treasure by Mahk */

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bronze");
  SetShort("a dull bronze ingot");
  SetId( ({ "bronze", "ingot" }) );
  SetAdjectives( ({ "dull","bronze" }) );
  SetLong("A rectanguler block of forged bronze, its soft surface still "
    "showing hammer blows.");
  SetMass(15*3/2);
  SetValue(200*3);
  SetDamagePoints(800);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

