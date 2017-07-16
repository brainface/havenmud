// Artanis@Haven (July 24, 2004)
// Fixed to not runtime when owner leaves
// Laoise, August 2004

#include <lib.h>
#include <std.h>

inherit LIB_SENTIENT;

void HealMe();
void HealMinorMe();
void FlushMe();
void HaltMe();

void KillMe();
int life = 200 + random(50);

static void create() {
  sentient::create();
  SetKeyName("spirit");
  SetId( ({ "spirit","spirit_kuthar" }) );
  SetAdjectives( ({ "ancient " }) );
  SetShort("an ancient spirit");
  SetLong(
     "This creature from beyond is a spirit that has been summoned "
     "into this plane of existance. It appears to have the shape "
     "of an ancient Draconian, only without the lower half of "
     "it's body. It is translucent and appears to cast no shadow "
     "of it's own. "
    );
  SetAdjectives( ({ "ancient" }) );
  SetRace("draconian", "spirit");
  SetSkill("faith", 1, 1);
  SetSkill("healing", 1, 1);
  SetSkill("melee attack", 1, 1);
  SetLevel(4);
  SetSpellBook( ([
     "touch" : 100,
     "mend" : 100,
     "dispel poison" : 100,
     "halt bleeding" : 100,
    ]) );
  SetInventory( ([
    ]) );
  SetNoCorpse(1);
  SetDie("%^CYAN%^The spirit fades in the wind and is gone.%^RESET%^");
 }

object Owner() { return find_living(GetOwner()); }


void heart_beat() {
  sentient::heart_beat();
  if(!find_living(GetOwner())) {
     eventDestruct();
     return;
  }
  if ((Owner()->GetHealthPoints() < (Owner()->GetMaxHealthPoints() - 50)) &&
     (Owner()->GetHealthPoints() > (Owner()->GetMaxHealthPoints() / 4))) {
     HealMinorMe();
  }
  if (Owner()->GetHealthPoints() <= (Owner()->GetMaxHealthPoints() / 4)) {
     HealMe();
  }
  if (Owner()->GetPoison() > 1) {
     FlushMe();
  }

  if (Owner()->GetBleeding() > 1) {
     HaltMe();
  }
  life--;
  if(!life) { KillMe(); }
  }

void HealMe() {
  eventForce("cast mend on " + Owner()->GetKeyName());
  }

void HealMinorMe() {
  eventForce("cast touch on " + Owner()->GetKeyName());
  }

void FlushMe() {
  eventForce("cast dispel poison on " + Owner()->GetKeyName());
  }

void HaltMe() {
  eventForce("cast halt bleeding on " + Owner()->GetKeyName());
  }


void KillMe() {
  eventDie();
  }
