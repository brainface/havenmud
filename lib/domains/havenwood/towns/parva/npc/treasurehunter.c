#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("fernando");
  SetShort("Fernando Cortez the Legendary Treasure Hunter");
  SetId( ({ "fernando", "treasure hunter", "cortez" }) );
  SetAdjectives( ({ "legendary" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Enlan");
  SetTown("TreasureHunter");
    SetClass("rogue");
    SetLevel(20); // not that great.
  SetLong(
    "The years have been hard on Fernando Cortez. His"
    " face is worn and weathered and his eyes have a hint"
    " of desperation to them. He is all skin and bones"
    " and appears as if his last meal was ages ago. His"
    " clothes are tattered and worn and have a multitude of"
    " stains on them."
    );
  SetAction(15, ({
   "!speak I was once known as the greatest treasure hunter"
     " of all time!",
   "!speak My... uh, my name is Fernando Cortez! Surely you've"
     " heard of the Great Fernando Cortez!",
   "!speak come, buy me a drink and I'll tell you of my"
     " adventures.",
   "!speak Drunk last night, drunk the night before... Gonna get"
     " drunk tonight like I never been drunk before. For when I'm"
     " drunk I'm as happy as can be!",
   "!speak Oh, do I know where some treasures are, do I!",
  }) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );

}
