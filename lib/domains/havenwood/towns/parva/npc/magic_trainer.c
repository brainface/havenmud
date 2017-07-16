//Selket@Haven
//2006
#include <lib.h>
#include "../parva.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("rebecca");
  SetId( ({ "rebecca", "labella", "trainer" }) );
  SetRace("elf");
  SetBaseLanguage("Enlan");
  SetGender("female");
  SetClass("evoker");
  SetTown("Parva");
  SetLevel(40);
  SetLimit(1);
  SetShort("Rebecca Labella, a trainer of magical skills");
  SetLong(
    "Rebecca is a ravishing youth whose great beauty is known "
    "to all of Parva. Her curvaceous body tells nothing of the "
    "great magics housed within, but she is able and willing "
    "to teach.");
  SetSpellBook( ([
    "chain lightning" : 100,
    "energy field" 	  : 100,
    "paralysis"  			: 100,
    "fireball"				: 100,
  	]) );
  SetAction(5, ({
    "!speak Do you seek training?",
    "!emote runs a hand through her luxurious hair.",
    "!cast energy field",
    }) );
  SetCombatAction(60, ({
    "!cast energy field",
    "!cast paralysis",
    "!cast fireball",
    "!cast chain lightning",
  	}) );
}
