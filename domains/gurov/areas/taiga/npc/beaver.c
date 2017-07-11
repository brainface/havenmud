//Illura@Haven
//Sept 2009
//beaver
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("arctic beaver");
    SetId( ({"beaver"}) ); 
    SetAdjectives( ({"arctic"}) );
    SetShort("an arctic beaver");
    SetLong(
      "The colossal beaver has lustrous white fur and a huge "
      "flat tail. His teeth are made for hewing stubborn logs "
      "but could easily turn against bone or steel.");
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(6);
    SetAction(5, ({
    "!emote slaps his tail furiously on the ground.",
    "!emote gnaws on a piece of pine.",
     "!emote gets wet in a small pond.",
                })  );
  SetCombatAction(10, ({
    "The beaver attempts to take a huge bite out of you!.",
    "The beaver gnashes his enormous teeth.",
    }) );
}
