/* dismount.c
 * dismounts a horsey
 * Note that stand up does the same thing
 * this is mostly included to prevent confusion
 */

#include <lib.h>
#include <position.h>
#include <rounds.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("dismount");
    SetRules("");
    SetErrorMessage("You don't have to clarify, simply 'dismount'");
    SetHelp(
      "Syntax: <dismount>\n"
      "Allows you to dismount whatever you are riding.\n"
      "(Usually, you can simply 'stand' as well.)\n\n"
      "See also: mount, sit, stand\n"
      "\n"
    );
}

mixed can_dismount() {
   if(this_player()->GetSleeping()) {
      return "You shouldn't fall asleep riding!";
   }
   if( this_player()->GetParalyzed() ) {
      return "You cannot do anything!";
   }
   if ( !this_player()->GetChair()) {
     return "You don't seem to be riding anything after all.";
   }
   return 1;
}


mixed do_dismount() {
  object horsey;

  horsey = this_player()->GetChair();

  // attempt to dismount whatever we're sitting on
  // if it accepted dismount, it was definitely a horse we
  // were mounted on.
  if ( horsey && horsey->GetRider() ) {
    this_player()->eventStand();
    return 1;
  } else {
    // stop trying to dismount chairs goshbangit
    this_player()->eventPrint("You don't seem to be on any sort of mount (try 'stand'ing?).");
    return 0;
  }

  // what are you trying to do? I don't know! stand up!
  this_player()->eventPrint("You don't seem to be on anything to dismount.");
  return 0;
}

