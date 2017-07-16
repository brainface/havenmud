//-- TORAK --//

#include <damage_types.h>
#include <lib.h>
#include "../ungkh.h"

inherit LIB_LEADER;

string race;

static void create() {
  leader::create();

  SetKeyName("flink");
  SetRace("ogre");
  SetClass("shaman");
  SetUniqueSkills( ([
    "healing" : 0,
    "enchantment" : 0,
    "necromancy" : 1,
    "planar magic" : 1,
    "evokation" : 2,
    ]) );
  SetLevel(58);
  SetGender("female");
  SetTown("Ungkh");
  SetReligion("Kuthar");
  SetMorality(0);
  SetId( ({
    "ogre","flink","shaman","shamaness",
    }) );
  SetAdjectives( ({
    "short","intelligent",
    }) );
  SetShort("Flink the Ancestrial Shamaness");
  SetLong("Unlike her cousins, Flink is shorter and weaker than "
          "most other ogres.  Instead she has developed her "
          "intelligence.  Now, she is counted as one of the most "
          "powerful worshipers of Kuthar in existance.");
  SetAction(1, ({
    "!snort",
    "!grunt",
    "!say teach you I can",
    "!exclaim the mysteries of the dead are mine",
    }) );
  SetCombatAction(30, ({
    "!cast will of old",
    "!cast crush",
    "!cast ancestrial protection",
    "!grunt",
    }) );
  SetNoJoin(1);
  SetCurrency("skins", 170 + random(200));
  SetTaughtSpheres( ({ "religion kuthar" }) );
  SetPlayerTitles( ([
    "newbie"     :  "the Neophyte Shaman",
    "mortal"     :  "the Spiritual Shaman",
    "hm"         :  "the Channel of Ancients",
    "legend"     :  "the One Who Speaks with the Dead",
    ]) );
}

void eventJoin(object who, string args) {
  race = who->GetRace();
  if(who->GetName() != "Liselle")
  if ((race != "ogre") && (race != "gnoll") && (race != "goblin") &&
      (race != "orc") && (race != "lizardman") && (race != "kobold") ) {
    eventForce("say Your race cannot learn the arts of shamanism!");
    return;
  }
  return leader::eventJoin(who, args);
 }
