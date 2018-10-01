/* Malveillant Quest Giver
   Aerelus (12/07/2007) */
#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Vorach the Quest Giver");
  SetShort("Vorach the Quest Giver");
  SetId( ({ "giver", "vorach" }) );
  SetAdjectives( ({ "quest" }) );
  SetRace("dark-elf");
  SetGender("male");
  SetTown("Malveillant");
  SetBaseLanguage("Eltherian");
  SetLong(
    "Vorach is a tall, dark, devious-looking man. He seems to have "
    "a permanent smirk on his face, as if he is plotting some kind "
    "of scheme. He is a respected figure in Malveillant, known to "
    "most dark-elves as the person to go to when you want something "
    "done with no questions asked. One could likely <as vorach for "
    "quests> if they were looking for work."
  );
    
  SetAction(15, ({
    "!speak You could ask me for a quest.",      
    "!speak You could request quests from me.",
    "!speak I might have some work for you, if you ask nicely.",    
  }) );
}
