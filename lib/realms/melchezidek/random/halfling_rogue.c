/* Arcanith Rogue Leader */  

#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
   ::create();
  SetKeyName("Perry");
  SetId( ({ "perry", "rogue", })  );
  SetAdjectives( ({ "scrawny", "halfling", "", }) );
  SetShort("Perry, the Confident");
  SetLong("Perry is rather small even for halfling standards."
          " His face is set in a devilish grin as if he knows"
          " something he should not. His body is lead and"
          " fit, something uncharacteristic of his race, yet"
          " his hands look strong and dextrous. His demeanor"
          " suggests he is capable of holding his own, should"
          " the need arise.");
  SetRace("halfling");
  SetBaseLanguage("Eltherian");
  SetTown("Lloryk");
  SetClass("rogue");
  SetLevel(35);
  SetGender("male");
  SetMorality(-100);

  SetAction(10,
     ({ "!emote glances around the room.",
	"!say If you wanted, I could teach you a thing or two...",
	"!say Sometimes I think that our ways are old, I do so covet"
        " a nice gold ring, or a necklace...",
	"!emote looks at his hands and smiles.",
	"!emote hums quietly to himself.",
	"!say Stealing? That's something I know nothing about....",
	"!say Who needs to worry about ownership, when I'm about",
	"!emote grins.",
     }) );
  SetInventory( ([ STD_KNIFE  "freeknife" : "wield knife" ]) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Loud",
    "mortal" : "the Newly Nimble",
    "hm"     : "the Cherished Acquirer",
    "legend" : "the Accomplished Liberator of Purses",
    "avatar" : "the Spider",
    "burglar" : "the Surefooted Roof Walker",
    ]) );
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 2,
    ]) );
}
