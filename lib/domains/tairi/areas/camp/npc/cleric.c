/*  A cleric of 'Taigis' */
#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cleric");
  SetShort("a cleric of Taigis");
  SetId( ({ "cleric" }) );
  SetAdjectives( ({ }) );
  SetRace("elf");
  SetClass("priest");
  SetSkill("pierce combat", 0, 1);
  SetSkill("evokation", 1, 1);
  SetSkill("pierce combat", 0, 1);
  SetMorality(-200);
  SetLevel(18);
  SetSpellBook( ([
     "protect" : 50,
     "holy shield" : 30,
     "flaming arrow" : 80,
     ]) );
  SetCombatAction(3, ({
      "!cast protect",
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
    CAMP_OBJ + "vest" : "wear vest",
    CAMP_OBJ + "cler_rap" : "wield rapier",
    ]) );
  }
