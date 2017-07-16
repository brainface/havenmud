/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: stone_axe.c
// Area: the dark pyramid
//
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

string LongD();
string ShortD();

static void create() {
  item::create();
  SetKeyName("axe");
  SetShort( (: ShortD :) );
  SetLong( (: LongD :) );
  SetHands(2);
  SetId( ({ "axe" }) );
  SetAdjectives( ({"stone","pulsating"}) );
  SetClass(16);
  SetWeaponType("hack");
  SetDamageType(SLASH|BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1400);
  SetMass(500);
  SetMaterials( ({ "natural",}) );
  SetProperties( ([
                   "history" : "This axe was crafted by a shaman in "
                               "ancient times. After finishing the "
                               "work, he sacrificed himself to bond "
                               "his spirit with the axe and a sword. "
                               "Since that time, it has been wielded "
                               "by one of the two guardians of the "
                               "temple.",
                   "magic" : "The axe has been bonded with the spirit "
                             "of the shaman."
               ]) );
  SetWield("As you wield the heavy axe, it starts trembling with "
           "power and slowly turns into a pulsating and deadly "
           "weapon!");
}

string ShortD() {
  if ( !GetWorn() )
    return "a stone axe";
  else
    return "a pulsating axe";
}

string LongD() {
  if ( !GetWorn() )
  return "This is a heavy and roughly cut stone axe. The stone from "
         "which it has been made it's very hard. The axe has a "
         "strange touch to it.";
  else
    return "This beautiful axe pulsates with every heartbeat of "
           "wielder. The handle is made of a shining white stone "
           "and the double-sided blade is made of black obsidian."
           "The blade has a blood-red ruby incrusted on each side.";
}
