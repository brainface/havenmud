#include <lib.h>
#include "../averath.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Grand Duke Louis");
  SetId( ({ "louis", "duke", "averath_person" }) );
  SetShort("Grand Duke Louis d'Averath");
  SetLong(
    "The old Duke is obviously past his prime. His disheveled hair and glazed "
    "eyes make him appear to be senile. There is a frail and pitiful look "
    "about him."
  );  
  SetAdjectives( ({ "grand", "duke", "averath", }) );
    
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");  
  AddCurrency("ducats", random(100));
  SetMorality(0);
  SetClass("fighter");
  SetLevel(25); 
  
  SetStat("durability", 5, 5);
  SetProperty("no bump", 1);
  SetInventory( ([
    ]) );
  SetAction(5, ({
    "The Duke wanders about aimlessly.",
    "!emote stops, looks intently at nothing, and continues on his way.",
    "!say Have you seen my son?",
    "!say My boy has wandered off playing with his friends again.",
    "!yell Oh sonny!  Where are you?",
    "!emote stops and drools a bit.",
    }) );
}