//Illura@Haven
//elk
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("elk");
  SetId( ({ "elk" }) );
  SetAdjectives( ({ "arctic" }) );
  SetShort("an arctic elk");
  SetLong(
    "The elk's hooves are larger than a draft horse's, yet make "
    "no sound as he moves through the snow, foraging lichen "
    "with gentle pulls of his sturdy, beveled teeth. His antlers "
    "stretch wide enough to provide shade for the nearby "
    "groundcover, and he looks as though he could definitely "
    "take a hit or two.");
  SetGender("male");
  SetClass("animal");
  SetLevel(15);
  SetRace("deer");
    SetAction(5, ({
    "!emote tramps his hooves gently.",
    "!emote hones his antlers against a tree with a scraping noise.",
    "!emote snuffles loudly, his breath turning into mist.",
                })  );
  SetCombatAction(10, ({
    "The elk lets out a loud bellow as he attacks.",
    "The elk charges at you with his antlers lowered!",
    }) );
}
