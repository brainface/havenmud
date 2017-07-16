#include <lib.h>
#include <daemons.h>
#define INVASION_DIR  "/std/invasions/"
inherit LIB_ROOM;
int Wave();

static void create() {
  room::create();
  SetClimate("indoors");
 
  SetAmbientLight(50);
  SetInventory( ([
   
     ]) );
  SetShort("an empty room");
  SetLong("This is Duuk's invasion room.");
  SetExits( ([
    "east" : "../workroom",
    ]) );
 }

void init() {
  add_action("trigger", "trigger");
  add_action("undead", "undead");
  add_action("jidoor", "jidoor");
  add_action("pbandit", "pbandit");
  add_action("parva", "parva");
  add_action("bandit", "bandit");
  add_action("demon", "demon");
  add_action("giant", "giant");
  add_action("pirate", "pirate");
  add_action("lizards", "lizards");
 }

int bandit(string useless) {
  object bandits = new("/std/invasions/bandit/bandit_inv");
  INVASION_D->eventRegisterInvasion(bandits, this_player());
  return 1;
  }

int trigger(string dir) {
  object invasion;
  string file;
  this_player()->eventForce("cd " + INVASION_DIR + dir);
  file = (this_player()->wild_card("*_inv.c"))[0];
  this_player()->eventPrint(file);
  invasion = new(file);
  INVASION_D->eventRegisterInvasion(invasion, this_player());
  return 1;
 }


int pbandit(string useless) {
    object bandits = new("/std/invasions/parva_bandit/bandit_inv");
   INVASION_D->eventRegisterInvasion(bandits, this_player() );
  return 1;
 }

int jidoor(string useless) {
  object templars = new("/std/invasions/jidoor/templar_inv");
  INVASION_D->eventRegisterInvasion(templars, this_player());
  return 1;
 }

int parva(string useless) {
    object templars = new("/realms/duuktsaryth/invasions/parva/templar_inv");
    INVASION_D->eventRegisterInvasion(templars, this_player() );
  return 1;
 }


int demon(string useless) {
   object demons = new("/std/invasions/demon/demon_inv");
    INVASION_D->eventRegisterInvasion(demons, this_player());
  return 1;
  }

int undead(string useless) {
  object undead = new("/std/invasions/undead/undead_inv");
  INVASION_D->eventRegisterInvasion(undead, this_player());
  call_out( (: Wave :), 20);
  return 1;
  }

int Wave() {
  object undead = new("/std/invasions/undead/undead_2_inv");
  INVASION_D->eventRegisterInvasion(undead, find_living("duuk"));
  return 1;
  }

int giant() {
  object giants = new("/realms/duuktsaryth/invasions/firegiant/firegiant_inv");
  INVASION_D->eventRegisterInvasion(giants, this_player());
  return 1;
  }

int pirate() {
  object pirates = new("/domains/southern_coast/invasions/pirate/pir_inv");
  INVASION_D->eventRegisterInvasion(pirates, this_player());
  return 1;
 }

int lizards() {
  object lizardmen = new("/std/invasions/lizardman/lizardman_inv");
  INVASION_D->eventRegisterInvasion(lizardmen, this_player());
  return 1;
 }

int CanReceive(object ob) {
  if (!userp(ob)) return 1;
  if (playerp(ob) && !(ob->GetTestChar()) ) {
    ob->eventPrint("You are prevented from going in that direction.");
    return 0;
    }
  return 1;
 }
