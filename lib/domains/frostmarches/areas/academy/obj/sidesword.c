/* A sidesword, cuz why not.
 * Essentially just the parvan smith's rapier
 * But mithril.
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  //description
  SetShort("a mithril sidesword");
  SetId( ({ "sidesword", "sword" }) );
  SetAdjectives( ({ "mithril", "side" }) );
  SetKeyName("sidesword");
  SetLong(
     "This is a finely crafted mithril sidesword, the sort "
     "entrusted to an officer or noble. The long, thin blade is "
     "sharpened to a razor edge, useful for broad sweeps "
     "or precise thrusts, and designed to be effective "
     "against any sort of combatant, armoured or not. Some "
     "writing has been etched onto the hilt." 
  );

  //other stuff
  SetClass(16);
  SetDamagePoints(800); // is 200 units less tough
  SetDamageType(PIERCE);
  SetMass(50); // is 20 units lighter
  SetMaterial( ({ "mithril" }) ); //mithril instead of metal
  SetRead(
    "Given to the Shadowguard Brijhzet, for her unfailing service "
    "to the city of Jidoor, On this Holday Summerwane the 12th "
    "Year 29. "
  );
  SetRepairDifficulty(25);
  SetValue(100); // costs 50 units more
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetWield( "The sidesword feels almost weightless in your grasp.");
}
