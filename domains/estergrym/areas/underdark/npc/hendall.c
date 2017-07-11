#include <lib.h>
inherit LIB_NPC;
#include "../underdark.h"

static void create() {
  npc::create();
  SetKeyName("Hendall");
  SetId( ({ "hendall", "hendall the angry", "hero" }) );
  SetShort("Hendall the Angry, Hero of Thurbard");
  SetLong(
    "This is Hendall the Angry, Hero of Thurbard. He is a medium "
    "sized dwarf, but not much else of his physical appearance can be seen, "
    "as he is in a thick suit of full plate armour. In his armour he looks "
    "very much like a large, walking tin can with large tufts of hair "
    "sticking out the eye, ear, and nose holes of the helmet. The smell "
    "of hot dwarf coming from him is overpowering. Hendall wanders the caves "
    "by himself, as his personality was so quick tempered, sneaky, greedy, "
    "lazy, and whiny, that his fellow soldiers to chase him away with sticks "
    "years ago."
  );
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(40);
  
  SetGender("male");
  SetCurrency("imperials", 100);
  SetMorality(-100);  
  SetAction(40, ({ 
    "!speak No one dares to challenge my might!",
    "!speak I am the master of all the world, none dare oppose me!",
    "%^BOLD%^CYAN%^Hendall trips over a rock and falls flat on "
    "his face with a %^BOLD%^RED%^crash.%^RESET%^",
    "%^BOLD%^CYAN%^Hendall pulls out a grimy rag and attempts "
    "to polish his armour and weapons, but only succedes in smearing "
    "dirt over them.%^RESET%^",
    "!speak Come Nathan. We go!",
    "%^BOLD%^CYAN%^Hendall pulls out a large bag of money and "
    "begins to count the %^YELLOW%^shiny coins.%^RESET%^",
    "!speak You have come to steal my money havn't you!",
    "!speak It will cost you 200 coins for the privilage of shaking my hand." 
  }) );
  SetCombatAction(30, ({
    "!speak Hey! No Fair!",
    "%^BOLD%^CYAN%^Hendall bangs and clangs around "
    "in his armour attempting to strike you , but fails.%^RESET%^",
    "%^BOLD%^CYAN%^Hendall offers to make peace and "
    "then hits you hard with a low blow.%^RESET%^",
    "!speak You can't actually think you can fight me in all my glory!",
    "%^BOLD%^CYAN%^Hendall yells 'Look out behind you!' and throws a handfull "
    "of %^BOLD%^YELLOW%^sand %^BOLD%^CYAN%^ in your eyes.%^RESET%^",
    "%^BOLD%^CYAN%^Hendall charges at you but trips over his own feet and "
    "falls to the ground with a horrendous %^BOLD%^RED%^crash.%^RESET%^",
    "%^BOLD%^CYAN%^Hendall yells that you are fighting dirty "
    "and to stop at once, and then knees you in the groin.%^RESET%^" 
  }) );
  SetInventory( ([
    U_OBJ + "hendall_axe" : "wield axe in right hand",
    U_OBJ + "hendall_bow" : "wield bow in left hand",
    U_OBJ + "hendall_armour" : "wear armour",
    U_OBJ + "hendall_shield" : "wear shield on left arm" 
  ]) );
}
