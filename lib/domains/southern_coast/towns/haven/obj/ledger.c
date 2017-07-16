/*  A tally ledger for votes of Imperial Senators. */
#include <lib.h>
inherit LIB_VOTE;

static void create() {
  ::create();
  SetKeyName("ledger");
  SetShort("a tally ledger");
  SetLong("This is a tally ledger of the votes of the Senators "
          "of Haven Town.");
  SetId( ({ "ledger", }) );
  SetAdjectives( ({ "tally", }) );
 }

mixed direct_vote_with_obj_for_str(string str) {
  if (this_player()->GetRank() != "Senator" ||
       this_player()->GetTown() != "Haven") {
     return "You cannot vote here!";
      }
  return 1;
 }
