/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: stone_sword.c
// Area: the dark pyramid
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

string ShortD();
string LongD();

static void create() {
  item::create();
  SetKeyName("sword");
  SetShort( (: ShortD :) );
  SetLong( (: LongD :) );
  SetHands(2);
  SetId( ({ "sword" }) );
  SetAdjectives( ({"stone","pulsating"}) );
  SetClass(16);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1200);
  SetMass(350);
  SetMaterials( ({ "natural", }) );
  SetProperties( ([
                   "history" : "In ancient times, a shaman started "
                               "to work on a huge stone and he "
                               "eventually carved a sword out of it. "
                               "He did the same with another items "
                               "and then he sacrificed himself to bond "
                               "his spirit with the items.",
                   "magic" : "The sword has been bonded with the spirit "
                             "of its crafter."
               ]) );
  SetWield("As you wield the stone sword, it transforms into a "
           "beautiful sword made out of different stones!");
}

string ShortD() {
  if ( !GetWorn() )
    return "a stone sword";
  else
    return "a pulsating sword";
}

string LongD() {
  if ( !GetWorn() )
  return "This is a heavy and roughly cut stone sword. The edges "
         "of the blade are dull and deriorated. It has a "
         "strange touch to it.";
  else
    return "This beautiful sword pulsates with every heartbeat of "
           "wielder. The hilt is made of a glowing white stone and "
           "the blade is made of black, sharp obsidian. The blade "
           "has a shining blue opal at its base near the hilt.";
}

