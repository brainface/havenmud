/* Ungkh--Gnoll merchant
 * Ranquest@Haven
 * 02/15/99
 */

//-- fixed UTTERLY by torak  --//
//-- only had 2 prime, and very bad titles --//
//-- removed a few actions, like 'say i am the class leader' --//

#include <lib.h>
#include <std.h>
#include "../ungkh.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Ungkh");
  SetKeyName("Cronag");
  SetShort("Cronag, a merchant prince");
  SetLong(
    "Cronag is revered amongst the gnolls, and the merchants"
    " in general, for his extraordinary gift for selling the most"
    " useless of items to the most recalcitrant of buyers. "
    " Consequently, he has used his wealth to set himself in such"
    " luxury that is unseen elsewhere in Ungkh.");
  SetId( ({ "cronag","citizen","gnoll","merchant" }) );
  SetAdjectives( ({"prince"}) );
  SetRace("gnoll");
  SetGender("male");
  RemoveLanguage("Gnollish");
  SetLanguage("Uruk",100,1);
  SetClass("merchant");
  SetLevel(50);
  SetPlayerTitles( ([
    "newbie" : "the Knickknack Trader",
    "mortal" : "the Bric-a-Brac Swindler",
    "hm"     : "the Ornamental Charlatan",
    "legend" : "the Bauble Dealer",
    "avatar" : "the Legendary Merchant"
    ]) );
  SetAction(1, ({
    "!emote relaxes in his luxury.",
    "!emote sighs contentedly.",
    }) );
  SetFriends( ({"gnoll"}) );
  SetCombatAction(1, ({
    "!yell help!",
    "!exclaim do you realize who I am?",
    "!yell guards!",
    }) );
  SetInventory( ([
    U_OBJ + "javelin" : "wield javelin",
    U_OBJ + "toga" : "wear toga",
    ]) );
  SetUniqueSkills( ([
    "projectile attack" : 1,
    "stealth" : 1,
    "fishing" : 1,
    "weapon smithing" : 2,
    "wood working" : 2,
    "natural working" : 2,
    ]) );
  SetFreeEquip( ([
    "/std/weapon/projectile/bow_long_newbie" : 1,
    ]) );
  }
