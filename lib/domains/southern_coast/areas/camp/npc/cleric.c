/*  A cleric of 'Taigis' */
#include <lib.h>
#include <std.h>
#include "../camp.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("cleric");
  SetShort("a cleric of Taigis");
  
  SetId( ({ "cleric" }) );
  SetAdjectives( ({ }) );
  SetRace("elf");
  SetTown("all");
  SetClass("priest");
  SetReligion("Saahagoth");
  SetUniqueSkills( ([
    "pierce combat" : 1,
    "blunt combat" : 0,
     ]) );
  SetMorality(-1000);
  SetLevel(18);
  SetSpellBook( ([
     "holy shield"   : 100,
     "shockwave"     : 100,
     "flaming arrow" : 100,
     ]) );
  SetFreeEquipment( ([
    STD_PIERCE "epee" : 1,
    ]) );
  SetCombatAction(50, ({
      "!cast shockwave",
      "!cast holy shield",
      "!cast flaming arrow",
       }) );
  SetAction(3, ({
     "!emote looks to the decorations on the tent in mystical awe.",
     "!say Lord Taigis, when shall you return!",
     "!sigh",
     "!sob",
     "!whisper He shall return, oh yes...",
       }) );
  SetLong("This is a cleric of Taigis, the long lost Elven Lord "
          "of Chaos. His demeanor suggests that he is something to "
          "be feared, and also that he is slightly insane.");
  SetGender("male");
  AddStatBonus("strength", 15);
  SetInventory( ([
    CAMP_OBJ + "/vest" : "wear vest",
    CAMP_OBJ + "/cler_rap" : "wield rapier",
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Initiate of the Fallen God",
    "mortal" : "Cultist $N the Follower of the Fallen God",
    "hm"     : "the Bringer of Chaos",
    "legend" : "the Taint of Taigis",
    "avatar" : "the Mark of Chaos",
    ]) );
}
