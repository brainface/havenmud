// mahkefel 2014--stop stupid ferry captains dumbing

#include <lib.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
}

void heart_beat() {
  object ship = environment();
  object *enemies = ({ });
  string com = 0;
  ::heart_beat();
  if (Wait > 0) {
    Wait--;
    return;
  }
  if (!ship) { return; }
  if (vehiclep(ship) && !environment(ship)) {
    eventDestruct();
    return;
  }
  /* This is to clean up useless ships that aren't affecting players and are out of stores. */
  if (ship->GetShipStores() == 0) {
    com = "scuttle ship";
    foreach(object o in all_inventory(ship)) {
      if (userp(o)) com = 0;
    }
  }
  if (!id(ship->GetOwner()) && !id(ship->GetCaptain())) {
    /* I am neither the Captain nor the Owner */
    if(GetProperty("will_pirate")) com = "pirate";
  }
  if (!com) { /* Ok.  We're not scuttling the ship.  Are we in combat? */
    enemies = ship->GetShipEnemies();
    if (!enemies) { enemies = ({ }); }
    enemies = filter(enemies, (: $1 :) );
    foreach(object e in enemies) {
      if (environment(e) != environment(ship)) enemies -= ({ e });
      }
    if (sizeof(enemies)) { com = eventShipCombat(enemies); }
  }
  if (!com) {
    com = eventCheckRepairs();
  }
  if (GetInCombat()) { com = ""; } /* We're in hand-to-hand. */
  if (!com) { /* Ok, no valid combat command.  Are we on a path to go somewhere? */
    if (sizeof(ShipWanderPath)) {  com = eventDecidePath(); }
    }
  if (!com) { /* Ok.  I have stores, I am not in combat, and I don't have a ShipWanderPath */
    if (ShipWander) { com = eventShipWander(); }
    }
  /// removing--causes ferrycaptains to dumb all the dumbs.
  //if (!sizeof(players())) { com = "scuttle ship"; }
  /* Ok, do we have a valid command? */
  if (com) {
    if (!stringp(com)) return;
    eventForce(com);
    LastCommand = com;
    }
}

