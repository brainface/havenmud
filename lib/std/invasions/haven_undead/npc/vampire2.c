// Undead invasion of Haven
// Raises its victims as vampyres
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("vampire");
  SetShort("a vampire");
  SetId( ({ "vampire", "undead_inv" }) );
  SetLong(
    "This pale faced human is a vampire, not someone to be "
    "trifled with by the weak."
  );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetEnemyTown("Haven");  
  SetLevel(25);
  SetUndead(1); 
  SetNoCorpse(1);
  SetMorality(-350);
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go east", "go east", "go south", "go south", "go south",
    "go east", "go east", "go east", "enter shop",
    "attack naythen",
  }) );
}

void eventEnemyDied(object deadboy) {
  object newvamp;

  newvamp = new(__DIR__ + "vamp_corpse");
  newvamp->SetRace(deadboy->GetRace());
  newvamp->SetShort(deadboy->GetShort());
  newvamp->SetLong(deadboy->GetRawLong());
  newvamp->SetLevel(deadboy->GetLevel());
  newvamp->SetClass(deadboy->GetClass());
  newvamp->SetProperty("invader", 1);
  if (present("corpse", environment())) {
    present("corpse", environment())->eventDestruct();
   }
  newvamp->eventMove(environment());
  newvamp->eventForce("get all");
  newvamp->eventForce("wear all");
  foreach(object thing in all_inventory(newvamp)) {
    if (!(thing->GetWorn())) newvamp->eventForce("wield " + (string)thing->GetKeyName());
   }
  if (GetInvasionObject()) {
  newvamp->SetInvasionObject(GetInvasionObject());
  GetInvasionObject()->AddInvader(newvamp);
    }
  newvamp->eventForce("follow vampire");
  eventForce("lead vampyre");
  invader::eventEnemyDied(deadboy);
}