/* Arcanith Rogue Leader */  

#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
   ::create();
  SetKeyName("Bistry");
  SetId( ({ "bistry", "rogue", "scavenger" })  );
  SetAdjectives( ({ "furtive", "kobold", "scrawny", }) );
  SetShort("a scrawny and furtive scavenger");
  SetLong("This is a small and very furtive looking kobold."
          " His fur is a dark blue and patchy from years of"
          " hardships. Around his muzzle are sores and boils"
          " that hint at a life long struggle with abuse.");


  SetRace("kobold");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetClass("rogue");
  SetLevel(15);
  SetGender("male");
  SetMorality(0);

  SetAction(10,
     ({ "!emote looks around for something to eat.",
        "!emote picks his nose.",
        "!emote quirks his eyebrows.",
        "!say I know something about something, if you know what I mean",
        "!say ask me how to survive, and I just might teach you",
         }) );
  SetInventory( ([ STD_KNIFE  "freeknife" : "wield knife" ]) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Clumsy",
    "mortal" : "the Barely Noticeable",
    "hm"     : "the Inconspicuous",
    "legend" : "the Faceless Vagabond",
    "avatar" : "the One and Only No One",
    ]) );
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 2,
    ]) );
}
