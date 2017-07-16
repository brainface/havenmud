/*  LIB_STOREROOM
 * For use by vendors to control supply and 
 * demand but still maintain ability to buy
 * objects from players.  
 * Use at discretion.
 * Duuk@Haven 071497
 */

#include <lib.h>
#include <clock.h>
void sell_off();
void SetPurgeInterval(int x);
int GetPurgeInterval();
inherit LIB_ROOM;


static void create() {
  room::create();
  SetNoClean(1);
  set_heart_beat(3600 * 8); /* 8 hours */
 }

void heart_beat() {
  ::heart_beat();
  sell_off();
}

void sell_off() {
  if (sizeof(all_inventory())) {
    foreach(object thing in all_inventory() ) {
     if (!living(thing))
       thing->eventDestruct();
     }
  }
}

void SetPurgeInterval(int x) { return; }

int GetPurgeInterval() { return; }
