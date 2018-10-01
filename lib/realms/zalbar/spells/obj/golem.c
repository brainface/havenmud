#include <lib.h>
#include <damage_types.h>
#include <std.h>
inherit LIB_NPC;

string Summoner;

static void create() {
  ::create();
  SetKeyName("golem");
  SetId( ({ "golem" }) );
  SetShort("a golem");
  SetLong(
    "A golem is a large humanoid construct created either from the flesh "
	"of corpses or from ingots. A very powerful enchanter imbues planar "
	"energy into the construct bring it to life. "
    );
  SetRace("golem");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(75);
  SetMeleeDamageType(BLUNT|MAGIC);
  SetProperty("golem", 1);
  SetNoCorpse(1);
  SetDie("%^BOLD%^YELLOW%^With a flash, the golem shatters as the planar energy leaves its body.%^RESET%^");
}

string SetSummoner(string summon) { return Summoner = summon; }
string GetSummoner() { return Summoner; }
    
void heart_beat() {
  ::heart_beat();
  if (!Summoner) return;
  if (!find_living(Summoner)) {
    eventDestruct();
  }
}

