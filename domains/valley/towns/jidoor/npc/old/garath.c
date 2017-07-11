/* Garath, Druid leader
 * Ranquest@Haven
 * 02/12/99
 */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetReligion("Magildan","Magildan");
  SetKeyName("garath");
  SetId( ({"garath","mystic","tender"}) );
  SetAdjectives( ({"arch"}) );
  SetShort("Garath, the mystical tender of the groves");
  SetLong(
    "Gildor, the head mystic of the natural energies which make"
    " up the Magildan faith, looks to be in his early fifties."
    " The restful nature of the grove in which he lives has bestowed"
    " longevity on him, and the natural ageing process has slowed,"
    " until the only way to estimate his age is by the experienced"
    " look in his eyes, giving away the centuries that lie behind"
    " him.");
  SetRace("sprite");
  SetGender("male");
  SetClass("mystic");
  SetLevel(60);
  SetSpellBook( ([
    "barkskin" : 100,
    "enhanced natural veil" : 100,
    "lunar charge" : 100,
    "natural veil" : 100,
    "scatter protections" : 100,
    "solar charge" : 100,
    "vine wall" : 100,
    "transmorph" : 100,
    "thicken skin" : 100,
    ]) );
  SetAction(1, ({
    "!ask would you like me to teach you some spells, little one?",
    "!emote mumbles a little prayer.",
    "!exclaim what a glorious day this is!",
    "!emote feeds a small squirrel.",
    }) );
  }
