
#include <lib.h>
inherit LIB_VOTE;

static void create() {
  ::create();
  SetKeyName("booth");
  SetShort("the Jidoor Voting Booth");
  SetLong("The citizens of Jidoor utilize this voting booth to "
           "cast their votes on various issues.  Only the mayor "
           "may view the contents of the votes.");
  SetBoothId("jidoorbooth");
  SetId( ({ "booth" }) );
  SetAdjectives( ({ "voting" }) );
 }
