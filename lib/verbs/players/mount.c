/*    /verbs/players/sit.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 960711
 *    Version: @(#) sit.c 1.7@(#)
 *    Last Modified: 96/12/21
 */

#include <lib.h>
#include <position.h>
#include <rounds.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("mount");
    SetRules("LIV");
    SetErrorMessage("Mount what?");
    SetHelp(
      "Syntax: <mount (horsie)>\n"
      "Allows you to mount a steed of some sort, to ride it around."
      "(You can also 'sit' as a passenger on some steeds ridden by others."
      "\n\n"
      "See also: dismount, sit, stand"
    );
}

mixed can_mount_liv() {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
   if( this_player()->GetParalyzed() ) {
      return "You cannot do anything!";
   }
   /*handled in do
   if( this_player()->GetChair() && this_player()->GetChair() != this_object() ) {
   	 return "You can't do that while sitting on " + 
   	 this_player()->GetChair()->GetShort() + 
   	 "! (Stand up and then mount <horse> to ride a horse.)";   
	 }*/
   return 1;
}


mixed do_mount_liv(object horsey) {

  // can't mount while sitting in a lawn chair
  // also handle going from sitting as passenger to mounting the same object
  if( this_player()->GetChair() && this_player()->GetChair() != horsey ) {
    this_player()->eventPrint("You can't do that while sitting on " + 
      this_player()->GetChair()->GetShort() + 
      "! (Stand up and then mount <horse> to ride a horse.)");
    return 0;
   } 
  
  // check ownership
  if (horsey->GetOwner() != this_player()->GetKeyName() ) {
    this_player()->eventPrint(capitalize(horsey->GetName()) 
      + " will absolutely not let that happen.");
    return 0;
  }

  // check size restrictions
  if (this_player()->GetSize() > horsey->GetSize() ) {
    this_player()->eventPrint("You're too large to ride such a small creature.");
    return 0;
  }
  
  // prevent mounting daisy chains
  if (horsey->GetChair()) {
  	this_player()->eventPrint("You can't ride "+horsey->GetShort() + 
  	  " while it's sitting on " + horsey->GetChair()->GetShort() + ".");
  	return 0;
  }
  
  return horsey->eventReceiveMount(this_player());
}

