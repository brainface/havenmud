/*  A small yet wicked knife for the goblins
 */
#include <lib.h>
#include "../goblins.h"
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("wicked knife");
  SetShort("a wicked looking knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "wicked", "wicked looking" }) );
  SetLong("This small knife has a serrated edge that looks deadly.");
  SetClass(13);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH|PIERCE);
  SetWeaponType("knife");
  SetDamagePoints(800);
  SetValue(50);
  SetMass(30);
  SetRepairSkills( ([
      "weapon smithing" : 1,
      "metal working" : 1,
      ]) );
  SetRepairDifficulty(10);
  SetMaterial( ({ "metal" }) );
  }
