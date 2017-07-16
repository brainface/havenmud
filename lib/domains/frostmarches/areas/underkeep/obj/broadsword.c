//
// a magical broadsword
// created by Ranquest@Haven
//
#include <damage_types.h>
#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_LISTEN;

static void create() {
  item::create();
  SetShort("a deadly sharp sword");
  SetLong(
    "This sword exudes deadliness. Its blade is a thin as a hair, yet "
    "incredibly strong and supple. Runes have been carved into its "
    "hilt and pommel in a long forgotten tongue.");
  SetKeyName("sword");
  SetId("sword");
    SetAdjectives( ({ "deadly" , "sharp" ,"magic" }) );
  SetProperty(
    "history",
      "This sword was crafted by the famous Yuk Foo Tuk for His "
      "Majesty King Radchek's Royal Bodyguard. This was originally "
      "one of a set of twelve, and magically enhanced to be deadly "
      "against any foe.");
  SetProperty(
    "magic",
      "This sword has been enchanted for extra lethality.");
  SetDamagePoints(4000);
  SetClass(18);
  SetMaterial("metal");
  SetRepairSkills( ([
    "weapon smithing" : 3,
    "metal working" : 3,
    ]) );
  SetVendorType(VT_WEAPON);
    SetRepairDifficulty(35);
    SetValue(1500);
    SetMass(100);
    SetWeaponType("slash");
    SetDamageType(SLASH|SHOCK);
  SetWield( "The blade seems to purr with pleasure as you wield it." );
  SetListen( "A faint hum can be heard from the sword." );
  SetHands(2);
}


string GetListen(string str) {
  return listen::GetListen(str);
}
/* Approved by Duuktsaryth on Sun Nov 22 18:23:26 1998. */
