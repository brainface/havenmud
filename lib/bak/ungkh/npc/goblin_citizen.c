/* Goblin citizen
 * Ranquest@Haven
 * 02/14/99
 */
#include <lib.h>
#include "../ungkh.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetShort("a goblin citizen");
  SetLong(
    "Back hunched, this goblin stares at the world through shifty,"
    " suspicious yellow eyes, believing everyone to be as untrustworthy"
    " as he.");
  SetKeyName("goblin citizen");
  SetId( ({"goblin","citizen","ungkher"}) );
  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetGender("male");
  SetClass("valkyr");
  SetLevel(9);
  SetCurrency("skins",random(80) );
  SetAction(1, ({
    "!emote stares at you suspiciously.",
    "!emote peers at something inside his coat.",
    "!emote peers over his shoulder.",
    }) );
  SetFriends( ({ "goblin" }) );
  SetCombatAction(3, ({
    "!yell guards!",
    "!exclaim you will pay for this!",
    "!exclaim help! a madman!",
    "!scream",
    }) );
  SetInventory( ([
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );
  }
