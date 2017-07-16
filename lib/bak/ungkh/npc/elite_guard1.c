/* Ungkh -- ogre elite guard
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <std.h>
#include "../ungkh.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetRace("ogre");
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk",100,1);
  SetGender("male");
  SetMorality(10);
  SetClass("barbarian");
  SetLevel(45 + random(10));
  SetShort("an elite guard");
  SetLong(
    "This huge towering bulk of muscle is one of the finest"
    " guards of Ungkh. His formidable size and glowering eyes"
    " indicate this is not someone to mess with.");
  SetKeyName("guard");
  SetId( ({"ogre","guard","ungkher" }) );
  SetAdjectives("elite");
  SetAction(3, ({
    "!say who you?",
    "!say what you do?",
    "!emote scratches himself.",
    }) );
  SetCombatAction(4, ({
    "!grunt",
    "!exclaim you bad! Me kill!",
    "!yell you die!",
    }) );
  SetFriends( ({"guard","hunh","ogre","citizen"}) );
  SetInventory( ([
    U_OBJ + "bigsword" : "wield sword",
    U_OBJ + "tunic" : "wear tunic",
    ]) );
  SetWander(6);
  }
