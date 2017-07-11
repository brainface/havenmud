/*  A spectre */
#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;
int eventCheckPlayer();

static void create() {
  ::create();
  SetKeyName("spectre");
  SetShort("a wispy spectre");
  SetInvis(1);
  SetRace("wraith");
  SetUndead(1);
  SetUndeadType("spectre");
  SetNoCorpse(1);
  SetDie("The spectre dissipates into nothingness.");
  SetResistance(ALL_PHYSICAL, "immune");
  SetClass("rogue");
  SetLevel(70);
  SetMorality(-500);
  SetWander(5);
  SetId( ({ "spectre", "tower_wander" }) );
  SetAdjectives( ({ }) );
  SetLong("This is a spectre, one of the remaining guardians of "
          "the evil Mage Tower in Haven Town.");
  SetEncounter( (: eventCheckPlayer :) );
  SetMeleeAttackString("chill touch");
  SetMeleeDamageType(MAGIC|COLD);
  }

int eventCheckPlayer() {
  object who = this_player();
  if (userp(who)) {
     SetAttack(who);
     return 1;
    }
  else return 0;
 }
