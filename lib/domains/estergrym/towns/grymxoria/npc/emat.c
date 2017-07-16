
// Bartender for Grym
// Laoise
// 2005

#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("emat");
  SetShort("emat, the bartender of the Rotting Elf");
  SetId( ({ "emat", "bartender" }) );
  SetLong(
    "Is fairly average looking, for a nosferatu. His bald head gleams faintly and "
    "he appears to keep his fangs neatly polished. A fanatical and holy glow "
    "seems to come from his black orbs. While not in the fighting shape of his "
    "youth, Emat appears prepared to handle most discord which might "
    "happen in his bar."
  );
  SetRace("nosferatu");
  SetClass("fighter");
  SetLevel(15);  
  
  SetGender("male");  
  SetMorality(-1500);
  SetLocalCurrency("bloodgems");
  SetMenuItems( ([
    "water" : STD_MEAL "water",
    "bread" : STD_MEAL + "food/bread",
    "cheese" : STD_MEAL + "food/cheese",
    "steak" : STD_MEAL + "food/steak",
    "scotch" : STD_MEAL + "alcohol/scotch",
    "ale" : STD_MEAL + "alcohol/ale",
  ]) );
  SetAction(5, ({
    "Emat survey his bar with a proprietary air, making sure all is "
    "as it should be.",
    "Emat pauses in his duties and glances towards the effigy "
    "set behind the bar.",
  }) );
}
