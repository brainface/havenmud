
// Magildan Mystic Leader for Gurov
// Laoise
// 2005

#include <lib.h>
#include <daemons.h>
#include <std.h>

inherit LIB_LEADER;
static void create() {
 leader::create();
  SetKeyName("ythen");
  SetShort("ythen the Explorer of the Arcane");
  SetId( ({ "ythen", "mystic" }) );
  SetAdjectives( ({ "magildan" }) );
  SetLong(
    "Gossamer wings are visible just behind the head of this "
    "small sprite. Petite even for his race, Ythen still manages "
    "to radiate an aura of power. His eyes are a strange swirl of "
    "green and manage to appear both far-away and extremely "
    "intense."
  );
  SetRace("sprite");
  SetGender("male");
  SetNoMulti(1);
  SetClass("mystic");
  SetLevel(75);
  SetMorality(60);
  SetReligion("Magildan","Magildan");
  SetTown("Gurov");
  SetBaseLanguage("Gurovian");
  SetInventory( ([ 
    STD_CLOTHING + "body/dgreen_vsmall" : "wear robe",
  ]) );
  SetAction(5, ({
    "Ythen's eyes seem to glow and shift, causing a pattern "
      "of green light to waver through the temple.",
    "Ythen's eyes close briefly and he seems to gather himself, "
      "causing his surrounding aura to pulse briefly.",
    "!say Learn the way of the mystic and find your way to power.",
    "!say Follow not the ways off good or evil, but instead that of "
      "power.",
    "!say Join Magildan if you yearn for knowledge.",
    //"!cast mesmer barrier",
    //"!cast wall of wood",
  }) );
  /*SetCombatAction(30, ({
    "!cast chain lighnting",
    "!cast enhanced fireball",
    "!cast mesmer barrier",
    "!cast summon golem",
    "!cast wall of wood",
  }) );
  SetSpellBook( ([
    "chain lightning" : 100,
    "enhanced fireball" : 100,
    "mesmer barrier" : 100,
    "summon golem" : 100,
    "wall of wood" : 100,
  ]) );*/
  SetPlayerTitles( ([
     "newbie" : "the Northern Mystic Acolyte",
     "mortal" : "the Northern Mystic",
     "hm"     : "the Greater Mystic of the North",
     "legend" : "the Legendary Magildan Patriarch",
     "avatar" : "the Pious Presenter of Magical Power",
  ]) );
}
