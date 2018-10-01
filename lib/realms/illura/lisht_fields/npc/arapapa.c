//Illura@Haven
//Sept 2009
//arapapa
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("arapapa");
  SetShort("arapapa, the tireless assistant");
  SetId( ({ "arapapa", "gnoll", "assistant" }) );
  SetAdjectives( ({ "tireless" }) );
  SetLong(
    "Arapapa is a young gnollish scribe trained to assist the "
    "master of the fields. She spends most of her time scurrying "
    "after him, scrawling figures on a piece of papyrus. She has "
    "great respect and a questionable amount of affection for "
    "Nkuku, as evidenced by her excessive preening around "
    "him. "
   );
  SetClass("fighter");
  SetLevel(20);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetAction(6, ({
    "!say Oh, yes sir, your eyes are very nice, sir.",
    "!say Oh, yes sir, I'm writing it all down, sir.",
    "!emote nods to herself and writes something down.",
    "!emote checks her reflection in the canal and primps accordingly.",
    "!emote moons over Nkuku with a sigh.",
    "!emote scribbles hurriedly on her papyrus.",
  }) );
}
