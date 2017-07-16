/*
 * Coded by Dunedain@Haven
 * 11 September 1997
 */

#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("goblin");
  SetShort("a weak looking goblin");
  SetLong("This is a weak looking goblin.  His bones are clearly "
          "visible and he looks around with a hungry look in his eyes. "
          "The goblin moves from place to place foraging for food.");
  SetId( ({ "goblin", "weak looking goblin" }) );
  SetAdjectives( ({ "angry", "weak looking" }) );
  SetClass("fighter");
  SetMorality(-175);
  SetWander(15);
  SetLevel(random(3)+4);
  SetGender("male");
  SetRace("goblin");
  SetCurrency("rounds",random(5));
  SetInventory( ([
                   "/std/weapon/knife/small_knife" : "wield knife",
              ]) );
}


/* Approved by Balishae on Thu Sep 11 13:50:51 1997. */
