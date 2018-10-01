#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Ariala");
  SetShort("Ariala");
  SetId( ({ "bard" }) );
  SetTown("Soleil");
  SetLong("Melody is a sweet muezzin with dark "
    "brown fur and eyes.  She is very "
    "short but appears to be "
    "agile and dexterous, making her "
    "very good at playing music."); 
  SetGender("female");
  SetMorality(2500);
  SetClass("bard");
  SetRace("muezzin");
  SetSkill("faith",90,1);
  SetSkill("healing",90,1);
  SetUniqueSkills( ([
    "healing" : 1,
  ]) );
  SetLevel(100);
  SetStat("agility",50,1);
  SetStat("durability",250,1);
  SetStat("dexterity",50,1);

  SetCurrency( ([
     "imperials" : random(300),
     "rupies" : random(100),
    "rounds" : random(80),
     ]) );
  SetSongBook( ([
    "song of forgotten battles" : 100,
  ]) );

}
