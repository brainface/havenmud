/* Ungkh lizardman guard
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <std.h>
#include "../ungkh.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetRace("lizardman");
  RemoveLanguage("Slith");
  SetLanguage("Uruk",100,1);
  SetGender("male");
  SetClass("fighter");
  SetLevel(25 + random(20));
  SetShort("a lizardman guard");
  SetLong(
    "A tall lizardman guard, he patrols the streets of Ungkh"
    " with a great deal of trepidation--"
    "because, if he arrests someone, then"
    " it might be an important personage who would wear"
    " the poor lizardman's skin as a new coat.");
  SetKeyName("guard");
  SetId( ({"lizardman","guard","ungkher" }) );
  SetAdjectives("tall");
  SetAction(3, ({
    "!say who are you?",
    "!say what is your purpose here?",
    "!emote scratches somewhere beneath his loincloth.",
    }) );
  SetCombatAction(4, ({
    "!emote hisses in anger.",
    "!exclaim don't hit me!",
    "!yell help me!",
    }) );
  SetFriends( ({"elite guard","hunh", "guard"}) );
  SetInventory( ([
    U_OBJ + "gob_loincloth" : "wear loincloth",
    U_OBJ + "javelin" : "wield javelin",
    STD_WEAPON + "knife/stiletto" : "wield stiletto",
    ]) );
  SetWander(6);
  }
