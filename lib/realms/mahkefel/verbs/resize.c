/*    /verbs/items/resize.c
 * Mahkefel 2019
 * makes a sock bigger or smaller
 *
 */

#include <lib.h>
#include <std.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("resize");
    SetRules("OBJ to STR");
    SetErrorMessage("Resize what to how big?");
    SetHelp("Syntax: <resize ITEM to SIZE>\n\n"
      "Adjust a garment or a piece of armour to a specific size. It requires\n "
      "some skill to adjust clothing correctly, and you will require some\n "
      "scrap materials to increase something in size.\n\n"
      "The possible sizes are: large, medium, small, and tiny.\n\n"
      "See help: <scrap>\n"
    );
}

mixed can_scrap_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   if(this_player()->GetParalyzed()) return "You can't move!";
   if(this_player()->GetStaminaPoints() < 50) return "You are too tired.";
   // prevent in combat
   return 1;
}

mixed do_resize_obj_to_str(object junk) {
  object who = this_player();
  int pro = 0;
  int con = 0;
  int result = 0;
  int we_broke_it = 0;
  object scrap;

  if (!environment(junk)) {
        who->eventPrint("something is terribly wrong.");
        return 0;
  }
  if(environment(junk) != this_player() ) {
        who->eventPrint("You can only resize something you're holding!");
    return 0;
  }
  if(junk->GetInvis()) {
        who->eventPrint("You can't see anything like that.");
        return 0;
  }
  if(!junk->GetMaterials() || !sizeof(junk->GetMaterials())) {
        who->eventPrint("You can't quite figure out what it's made of.");
        return 0;
  }
  if(junk->GetPreventDrop()) {
        who->eventPrint("It's like it doesn't want to be destroyed.");
        return 0;
  }
  if(junk->GetWorn()) {
        who->eventPrint("Not while you're wearing it!");
        return 0;
  }
  
  con  = junk->GetRepairDifficulty();
  con += junk->GetLevel();

  pro  = who->GetStatLevel("intelligence")/20;
  pro += who->GetStatLevel("coordination")/10;
  pro += who->GetLuck();

  foreach( string material in junk->GetMaterials() ) {
    result = who->eventCheckSkill(material + " working", con, pro, 0);
    if (result <= 0) {
      who->eventPrint("You can't seem to salvage any " + material + " from this.");
    } else {
      scrap = new(STD_CRAFTING + "survival/scrap_" + material);
      //debug(STD_CRAFTING + "survival/scrap_" + material);
      if (scrap) {
        we_broke_it = 1;
        send_messages("tear", "$agent_name $agent_verb " + scrap->GetShort() +
          " from " + junk->GetShort() + ".", who, 0, environment(who));
        scrap->eventMove(who);
        who->AddStaminaPoints(-50);
        if (who->GetStaminaPoints() < 50) {
          who->eventPrint("You're too tired to continue properly, and mangle the rest.");
          break;
        }
      } else {
        who->eventPrint("You can't seem to salvage any " + material + " from this.");
      }
    }
  }

  // if we recovered any scrap, assume the item is damaged beyond repair.
  if (we_broke_it) {
    junk->eventDestruct();
  } else {
        send_messages("resist", "$target_name $target_verb $agent_possessive_noun "
          "attempts to tear it apart!", who, junk, environment(who));
  }

  return 1;
}

