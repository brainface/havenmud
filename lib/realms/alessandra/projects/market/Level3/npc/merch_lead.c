//  A Merchant Leader for Malveillant
//  Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create(){
  ::create();

  SetKeyName("donvitoro");
  SetId( ({"merchant", "trainer", "racketeer", "donvitoro", "man", "dark-elf"}) );
  SetAdjectives( ({"shrewd", "looming"}) );
  SetShort("donvitoro, the Shrewd Racketeer");
  SetLong(
     "Donvitoro is a looming figure. His raven hair is neatly kept, and his "
     "black suit is meticulous. He is known for his bargaining skills "
     "and backroom dealings, and all the residents of Malveillant know he is "
     "not a man to be trifled with."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetReligion("Soirin");
  SetClass("merchant");
  SetLevel(65);
  SetCurrency("roni", 1000);
  SetInventory( ([
     ]) );
  SetPlayerTitles( ([
     "newbie" : "the Foolish Marketer",
     "mortal" : "the Savvy Trader",
     "hm"     : "the Cunning Backroom Dealer",
     "legend" : "the Perfidious Trafficker of Goods",
     "avatar" : "the Astucious Agent",
     ]) );
  SetFreeEquip( ([
     STD_KNIFE       "small_knife" : 1,    
     ]) );
  SetFriends( ({""}) );
  SetAction(5,({
     "!emote smiles seductively.",
     "!emote glances slyly about the room.",
     "!emote looks smug.",
    }) );
  SetCombatAction(5,({
     "!emote slips easily past your clumsy attack.",
     "!yell Scum!",
     }) );
}
