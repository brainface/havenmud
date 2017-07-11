#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("gold link necklace");
   SetShort("a gold link necklace");
   SetId( ({ "link","links","necklace" }) );
   SetAdjectives( ({ "gold","golden","link" }) );
  SetLong("Thin strips of gold form links to create this necklace.");
   SetMass(5);
   SetValue(50);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
   SetVendorType(VT_ARMOUR|VT_TREASURE);
   SetArmourType(A_AMULET);
   SetDamagePoints(240);
   SetWear("The gold links are a little cold.");
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(25);
   SetRepairSkills( ([
                       "metal working" : 5,
                       "armour smithing" : 5,
                  ]) );
}
