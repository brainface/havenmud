/*   Portia@Haven
     2-8-99
     A test for players to see if they are
     cool enough to be angels.
 */

#include <daemons.h>
#include <lib.h>
#define ANGEL_TEST_OBJECT "/secure/obj/angeltest"
#define ANGEL_CLOSED 0
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string useless) {
  object ob;
  if(ANGEL_CLOSED)
    return "We currently have a full group of angels and are not accepting applications at this time.  Please try back.";
  ob = new(ANGEL_TEST_OBJECT);

  if (!ob )
    return "Error : No Object Loaded";
  ob->eventMove(this_player());
  ob->eventStartTest();
  return 1;
}


string GetHelp() {
  return ("Syntax:         \"angeltest\"   \n\n\n"
          "This command initiates the test one must pass to become "
          "an Angel of Kailie.  Be warned, this is a LONG test. "
          "Submitting an application does not guarantee you a spot "
          "in the Immortal ranks.  It will take several days once your "
          "test is reviewed to make a decision, so be patient.");
 }
