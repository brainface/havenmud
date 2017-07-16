/* Ungkh -- Rogue Leader
 * Ranquest@Haven
 * 02/15/99
 */

//-- fixed by el torak, le awesome el sageo --//

#include <lib.h>
#include "../ungkh.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Ungkh");
  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetGender("female");
  SetClass("rogue");
  SetLevel(50);
  SetKeyName("Aliss");
  SetId( ({"aliss","goblin","citizen"}) );
  SetShort("Aliss the sewer scum");
  SetLong(
    "Short and ugly are the two words which best describe the "
    "character which stands before you. A warty green skin "
    "covers her body.");
  SetAction(1, ({
    "!emote stares around nervously.",
    "!emote paces back and forth.",
    "!emote picks her nose.",
    }) );
  SetFriends( ({"goblin"}) );
  SetCombatAction(1, ({
    }) );
  SetPlayerTitles( ([
    ]) );
  SetCurrency("skins",300 + random(300) );
  SetInventory( ([
    STD_WEAPON + "knife/stiletto" : "wield stiletto",
    U_OBJ + "cloak" : "wear cloak",
    ]) );
  }
