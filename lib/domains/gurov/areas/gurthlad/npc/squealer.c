/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
inherit LIB_NPC;
 
static void create() {
  npc::create();
  SetKeyName("squealer");
  SetId( ({ "creature","squealer" }) );
  SetAdjectives( ({ "squat","armoured","armored","squealing" }) );
  SetShort("a squat armoured squealing creature");
  SetLong("It is a squat creature commonly known as a "
          "squealer. It appears to be a cross between "
          "a pig and an armadillo.  It has four cloven "
          "hooves and a hard shell on its back. It is "
          "rumored to be one of some crazed alchemist's experiments "
          "with race creation.");
  SetRace("squealer");
if(random(2))
  SetGender("male");
else
  SetGender("female");
  SetClass("animal");
  SetMorality(-5);
  SetLevel(3);
  SetAction(10, ({ "The squealer rubs its nose around on the ground "
                "looking for tubers.", "The squealer lets out an annoyed "
                "squeal.", "The squealer locates a juicy root and gobbles "
                "it up." }) );
  SetCombatAction(20, ({ "The squealer squeals angrily.", "The squealer "
                         "pulls its head under its armored back." }) );
}
