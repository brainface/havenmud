
/* A style teacher */
#include <lib.h>
inherit LIB_STYLE_TRAINER;

static void create() {
  ::create();
  SetKeyName("rakosk");
  SetShort("a very sturdy looking dwarf");
  SetLong("This dwarf is a short but sturdy looking fellow that "
          "appears to have been around the world a few times. "
          "He looks like something is on his mind and he would be "
          "willing to teach if given the chance. His known talents "
          "include sparring and brawling.");
  SetId( ({ "dwarf", "rakosk", "trainer" }) );
  SetAdjectives( ({ "sturdy", "very", "looking" }) );
  SetClass("fighter");
  SetLevel(35);
  SetRace("dwarf");
  SetGender("male");
  SetCombatStyleLevel("sparring", 75);
  SetCombatStyleLevel("brawling", 100);
  SetLimit(1);
  SetCurrency("glims", 50);
  SetInventory( ([
    ]) );
  SetAction(10, ({
    "!speak Aye, my ways are not for everyone",
    "!snort sarcastically",
    "!chuckle",
    "!snort derisively",
    "!emote looks around for someone to abuse.",
    "The light glints evilly off the eyes of Rakosk.",
    }) );
  SetMorality(-150);
}
