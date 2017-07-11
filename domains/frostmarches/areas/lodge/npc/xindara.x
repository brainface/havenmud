#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;
static void create() {
  npc::create();
  SetKeyName("Xindara");
  SetShort("Xindara the seeker of distrust");
  SetId( ({"nosferatu","xindara","guard","guardroom_blocker"}) );
  SetAdjectives( ({"fair","average"}) );
  SetRace("nosferatu");
  SetClass("fighter");
  SetLevel(27);
  SetMorality(-125);
  SetCurrency("crystals",random(10)+1);
  
  SetLong(
    "This female nosferatu is of a fair size for her race, without being "
    "overly muscular. She has a steady gleam to her eyes, which "
    "suggests that she is an able defender of her territory. Oddly "
    "enough she is smiling, which almost manages to give her "
    "the air of being decent. However, her posture shows extreme "
    "attitude, with one hand on her hip and the other holding her "
    "sword tightly. She is balanced lightly on both feet, suggesting "
    "that she is ready to brawl."
  );
  SetGender("female");
  SetAction(9, ({
  "!emote giggles evilly.",
  "!say Is there a purpose for you wee one?",
  "!emote glances at Rztsual.",
  }) );
  SetCombatAction(9, ({
  "!say I knew there was something about you the moment I saw you!",
  "!say Leave while you're ahead...or while you still have one.",
  "!cackle",
  "!disarm",
  }) );
  SetInventory( ([
  L_OBJ + "ribcage" : "wear armour",
  L_OBJ + "sword" : "wield sword",
  ]) );
}


/* Approved by Duuktsaryth on Sat Feb 19 16:36:24 2000. */
