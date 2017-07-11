#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

static void create() {
  npc::create();
  SetKeyName("wraith");
  SetResistance(ALL_PHYSICAL, "immune");
  SetResistance(SHOCK, "immune");
  SetDie("The wraith dispells into a fine mist.");
  SetNoCorpse(1);
  SetRace("wraith");
  SetInvis(1);
  SetEncounter(100);
  SetUndead(1);
  SetResistLevel(50);
  SetFearLength(10);
  SetFearType("undead chill");
  SetClass("rogue");
  SetLevel(random(40)+60);
  SetMorality(-250);
  SetShort("a wispy wraith");
  SetAdjectives( ({ "wispy" }) );
  SetId( ({ "wraith" }) );
  SetLong("This wispy phantasm is a wraith.  Its abilities to devour \n"
          "life intact are feared by those with common sense.  To those \n"
          "with the courage to stand and attack it, it can mean death.");
  }

void init() {
  npc::init();
  fear::init();
 }

int eventDie(object killer) {
  object undead_inv;
  object undead_inv_2;
  if (!random(720)) {
    undead_inv = new("/std/invasions/haven_undead/uih_inv");
  INVASION_D->eventRegisterInvasion(undead_inv, killer);
    undead_inv_2 = new("/std/invasions/haven_undead/uih_2_inv");
   INVASION_D->eventRegisterInvasion(undead_inv_2, killer);
  }
  return (npc::eventDie(killer));
  }
