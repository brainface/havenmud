#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("drigg");
  SetShort("Drigg the Quest Giver");
  SetId( ({ "giver", "drigg" }) );
  SetAdjectives( ({ "quest" }) );
  SetClass("merchant");
  SetLevel(65);
  SetRace("dwarf");
  SetGender("male");
  SetBaseLanguage("Runic");
  SetTown("Glimmerdin");
  SetLong(
    "Drigg is a powerfully built dwarf with large muscles covered in a thick, "
        "coat of curly hair. His face is scared with a sharp line following his "
        "chin line. His powerful arms, proof he has done his fair share of hard "
        "labor. Drigg is tasked with assigning quests to those in need of them. "
        "Those in need of a quest should <ask drigg for quests>."
    );
  
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(20, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
