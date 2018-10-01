/*    /verbs/items/attach.c
 * Mahkefel 2017
 * attaches a thing to a thing
 * using it for "attach mat to crafty table"
 */

#include <lib.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("attach");
    SetSynonyms("affix");
    SetRules("OBJ to OBJ");
    SetErrorMessage("Attach what to what?");
    SetHelp("Syntax: <Attach ITEM to WORKBENCH>\n\n"
      "Allows you to attach one item to another, such "
      "as yarn to a loom.\n\n"
      "Synonyms: affix\n\n");
}

mixed can_attach_obj_to_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   if(this_player()->GetParalyzed()) return "You can't move!";
   return 1;
}

mixed do_attach_obj_to_obj(object what, object storage) {
  object who = this_player(); 
  int legal = 0;

  // this is adirty terrible hack way to do this, the objects need
  // eventAttach which then checks for legality.
  if (what->GetProperty("craft_fiber") && storage->GetKeyName() == "wheel") {
    legal = 1; 
  } else if (what->GetKeyName() == "yarn" && storage->GetKeyName() == "loom") {
    legal = 1;
  }

  if (!legal) {
    who->eventPrint("That's not the proper place for that!");
    return 0;
  }  
  // end the troubled times.
  
  if (!what->eventMove(storage)) {
    who->eventPrint("There is not enough room on there!");
    return 0;
  }
  send_messages("attach", "$agent_name $agent_verb " + what->GetShort() + " to "
    + storage->GetShort() + ".",
    who, 0, environment(who));
  return 1;
}


