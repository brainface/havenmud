//Illura@Haven
//Sept 2009
//weasel
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("weasel");
    SetId( ({"weasel" }) ); 
    SetShort("a weasel");
    SetLong(
      "The weasel has dark fur except for its muzzle and tail, "
      "which are bright white. It seems well fed on a diet of "
      "dormice, but not very menacing.");
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
  SetLevel(4);
    SetAction(5, ({
    "!emote chitters grouchily.",
    "!emote bares his tiny teeth at you.",
    "!emote swishes his bushy tail from side to side.",
                })  );
  }
