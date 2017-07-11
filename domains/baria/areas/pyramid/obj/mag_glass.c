/*                                                                   */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("magnifying glass");
  SetShort("a big magnifying glass");
  SetLong("This is a magnifying glass used by Gihan to examine "
          "all sort of things at a close distance. It is made "
          "of a hard type of stone.");
  SetHands(1);
  SetId( ({ "glass" }) );
  SetAdjectives( ({"big","magnifying"}) );
  SetClass(4);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetDamagePoints(75);
  SetValue(50);
  SetMass(25);
  SetVendorType(VT_WEAPON);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([
                     "stone working" : 3,
                     "weapon smithing" : 3,
                 ]) );
}
