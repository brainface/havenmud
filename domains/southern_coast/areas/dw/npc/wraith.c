// Wraith in Haven Graveyard
// Triggers Undead invasions of Haven

#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;
inherit LIB_FEAR;
int SecondUndead();

static void create() {
  npc::create();
  SetKeyName("wraith");
  SetDie("The wraith dispells into a fine mist.");
  SetNoCorpse(1);
  SetRace("human", "wraith");
  SetInvis(1);
  SetEncounter(100);
  SetUndead(1);
  SetUndeadType("ghost");
  SetResistLevel(5);
  SetFearLength(5);
  SetFearType("undead chill");
  SetClass("rogue");
  SetLevel(5);
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
  object undead_inv = new(DIR_INVASIONS + "/haven_undead/uih_inv");
  if (!random(30))
  INVASION_D->eventRegisterInvasion(undead_inv, killer);
  call_out((: SecondUndead :), 150);
  return (npc::eventDie(killer));
  }

int SecondUndead() {
  object undead_inv_2 = new(DIR_INVASIONS + "/haven_undead/uih_2_inv");
  INVASION_D->eventRegisterInvasion(undead_inv_2, this_player());
return 1;
}
