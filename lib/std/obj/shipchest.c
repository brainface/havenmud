#include <lib.h>
#include <std.h>
inherit LIB_STORAGE;

int OkGet;
mixed CheckShip(object who);

static void create() {
  ::create();
  OkGet = 0;
  SetKeyName("sailor chest");
  SetId( ({ "chest", "SHIP_ENCOUNTER_CHEST" }) );
  SetShort("a heavy sailor's chest");
  SetAdjectives( ({ "sailor", "sailor's", "heavy" }) );
  SetLocked(1);
  SetLockStrength(40);
  SetClosed(1);
  SetPreventGet( (: CheckShip :) );
  SetLong("This chest seems to be sturdy and well made, enough to hold a "
          "pirate's treasure!");
  SetMass(1500);
  SetMaxCarry(1000);
}

mixed CheckShip(object who) {
  object env = environment();
  if (!env) return "Whoa.";
  if (living(env)) return "You must put the chest down to examine it.";
  if (who->GetKeyName() == env->GetOwner()) return 1;  /* I own the ship, I can move the chest. */
  if (!vehiclep(env)) return 1;                        /* The chest isn't in a ship. I can move it. */
  if (OkGet) return 1;
  return "You cannot get that right now.";
}

int SetOk(int x) { return OkGet = x; }
int GetOk() { return OkGet; }