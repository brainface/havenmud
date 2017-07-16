/* Ungkh orc guard
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <std.h>
#include "../ungkh.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(25 + random(20));
  SetShort("an orc guard");
  SetLong(
    "This orc looks very disgruntled, as he has been pressed"
    " into service when he would much rather be drinking and"
    " brawling.");
  SetKeyName("guard");
  SetId( ({"orc","guard","ungkher" }) );
  SetAdjectives("disgruntled");
  SetAction(3, ({
    "!say who are you?",
    "!say what is your purpose here?",
    "!emote snorts loudly.",
    }) );
  SetCombatAction(4, ({
    "!emote grunts in pain.",
    "!exclaim leave me alone!",
    "!yell guards!",
    }) );
  SetFriends( ({"elite guard","hunh", "guard", "orc"}) );
  SetInventory( ([
    U_OBJ + "tunic" : "wear tunic",
    STD_ARMOUR + "armour/shield/shield" : "wear shield",
    STD_WEAPON + "slash/shortsword": "wield sword",
    ]) );
  SetWander(6);
  }