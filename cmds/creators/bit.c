/*  Duuk */
#include <lib.h>
#include <damage_types.h>
inherit LIB_DAEMON;

mixed cmd() {
  int block, thru;
  object me = this_player();
  int a = 1;
  int inflicted; int blocked;


  inflicted = SLASH|COLD|MAGIC;
  blocked = PIERCE|SLASH;
  me->eventPrint("b & i" + (blocked & inflicted));

  while(1 << a != MAX_DAMAGE_BIT) {
       if ( (inflicted & 1 << a) && (blocked & 1 << a) ) block++;
       if ( (inflicted & 1 << a) && !(blocked & 1 << a) ) thru++;
        a++;
    me->eventPrint("B: " + block + "T: " + thru);
  }
  return 1;
 }
