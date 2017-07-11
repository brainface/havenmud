// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"
inherit LIB_TELLER;

void CheckThem();

static void create() {
  ::create();
  SetKeyName("bujak");
  SetId( ({ "bujak", "teller", "we_wander" }) );
  SetAdjectives( ({ "sulumus", "bank" }) );
  SetShort("Bujak the Sulumus Bank Teller");
  SetLong(
     "This tall and skinny man is the caretaker of the economic backbone of the "
     "Sulumus Trading Post. Although his physical appearance is lacking in any "
     "real apparent sense of style, he apparently is a rather intelligent "
     "individual, as money is his specialty. "
  );
  
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetClass("merchant");
  SetSkill("melee combat");
  SetLevel(8);
 
  SetInventory( ([
     S_OBJ + "shirt" : "wear shirt",
     S_OBJ + "pants" : "wear pants",
     STD_OBJ + "storage/pouch" : "wear pouch",
  ]) );
  SetFriends( ({
     "we_wander",
     }) );
  SetLimit(1);
  SetCurrency("imperials", random(25)+10);
  SetLocalCurrency("imperials");
  SetLocalFee(0);
  SetNonLocalFee(0);
  SetCurrencies( ({ "imperials" }) );
  SetBankName("Sulumus Bank");
  SetMorality(-10);
  SetEncounter( (: CheckThem :) );
  SetAction(3, ({
     "!say Can I help you?",
     "!say Here to do a little business?",
     "!hum",
     "!say Whenever you're ready...",
     "!say Although this small trading post doesn't look like much, you would be "
     "very surprised at how much money comes through here!",
  }) );
  SetCombatAction(2, ({
     "!say NO...NOOO!!...NOOOO!!!",
     "!say Ahhhhhhhhhhh!",
  }) );
}

void CheckThem() {

  if (random(100) > 75) {
     eventForce("say Hello! How can I help you today?");
  }
}
