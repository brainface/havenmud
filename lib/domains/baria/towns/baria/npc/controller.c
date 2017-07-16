#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Bauto the Quest Giver");
  SetShort("Bauto the Quest Giver");
  SetId( ({ "giver", "bauto" }) );
  SetAdjectives( ({ "quest" }) );
  SetRace("human");
  SetGender("male");
  SetTown("Baria");
  SetBaseLanguage("Barian");
  SetClass("fighter");
  SetLevel(15); // dude is old. knees gave out years ago.
  SetLong(
    "Bauto is an old and decrepit man now, but in his"
    " youth he was known as the most traveled Barian."
    " His knowledge and experience are sought by many"
    " aspiring adventurers in Baria and the surrounding"
    " area. One might <ask bauto for quests> if they were"
    " looking for something to do."
    );
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
    "!speak Oh my knees!",
    "!speak Why, when I was your age, I was battling"
           " nosferatu in Grymxoria!",
  }) );
  call_out( (:  eventForce, "sit down" :), 0); 
}
