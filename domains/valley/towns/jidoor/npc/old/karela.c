/* Karela -- Mystic Natural Evokation Leader
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetReligion("Magildan","Magildan");
  SetShort("Karela, a mystic of the grove");
  SetKeyName("karela");
  SetId( ({"karela","mystic"}) );
  SetLong(
    "Karela is a short lamrani, with twinkling brown eyes"
    " and long hair, which seems to shift between dark blonde"
    " and light brown. Her smile lights up her whole face, and"
    " she seems in harmony with everything. Her pale skin "
    " offsets the colour of her eyes beautifully.");
  SetRace("lamrani");
  RemoveLanguage("Dasinri");
  SetLanguage("Sprith",100,1);
  SetClass("mystic");
  SetGender("female");
  SetLevel(55);
  SetSpellBook( ([
    "condense air" : 100,
    "enhanced natural shield" : 100,
    "feast" : 100,
    "freeze" : 100,
    "heat" : 100,
    "hydrate" : 100,
    "lunar blast" : 100,
    "natural shield" : 100,
    "plant strike" : 100,
    "solar blast" : 100,
    "summon animal" : 100,
    "tangle" : 100,
    ]) );
  SetAction(1, ({
    "!say I can teach you some natural evokation spells.",
    "!ask Would you like me to teach you some spells?",
    "!emote sighs contentedly.",
    }) );
  }
