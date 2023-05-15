/*    /verbs/items/resize.c
 * Mahkefel 2019
 * makes a sock bigger or smaller
 *
 */

#include <lib.h>
#include <std.h>
#include <size.h>

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

mixed can_resize_obj_to_str() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   if(this_player()->GetParalyzed()) return "You can't move!";
   if(this_player()->GetStaminaPoints() < 50) return "You are too tired.";
   // prevent in combat
   return 1;
}

mixed do_resize_obj_to_str(object junk, string size) {
  object who = this_player();
  int pro = 0;
  int con = 0;
  int result = 0;
  int is_upsize = 0;
  float resize_ratio = 0;
  object *my_mats = ({});

  // get a list of all scrap in inventory
  object *my_scrap = filter(all_inventory(this_player()), (: strsrch(file_name($1),STD_CRAFTING + "survival/scrap_")==0 :));
  object scrap;


  mapping sizes = (["tiny" : SIZE_TINY,
		   "very small" : SIZE_VERY_SMALL,
		   "small" : SIZE_SMALL,
		   "medium" : SIZE_MEDIUM,
		   "large" : SIZE_LARGE,
		   "very large" : SIZE_VERY_LARGE,
		   "huge" : SIZE_HUGE,
		   "giant" : SIZE_GIANT,
		   ]);

/*  debug(STD_CRAFTING + "survival/scrap_");
  foreach (object n in all_inventory(this_player())) {
    debug(file_name(n));
    debug(strsrch(file_name(n),"crafting"));
    }*/
  
  if (!environment(junk)) {
        who->eventPrint("something is terribly wrong.");
        return 0;
  }

  if(junk->GetPreventDrop()) {
        who->eventPrint("It's like it doesn't want to be tailored.");
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
  
  if (member_array(size, keys(sizes)) == -1) {
    who->eventPrint(size + " is not a reasonable size.\n (The sizes are tiny, very small, small, medium, large, very large, huge, and giant.)");
    return 0;
  }
  
  if(environment(junk) != this_player() ) {
        who->eventPrint("You can only resize something you're holding!");
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

  //resize_ratio = sizes[size]/float(junk->GetSize());

  if (sizes[size] > junk->GetSize()) {
    is_upsize = 1;
  }


	    
  foreach( string material in junk->GetMaterials() ) {

    result = who->eventCheckSkill(material + " working", con, pro, 0);
    // check for skill check success, return 0 on fail
    if (result <= 0) {
      who->eventPrint("You can't figure out how to work this " + material + ".");
      return 0;
    } else {
      // check for player having the scrap material, return 0 on fail
      if (is_upsize){
        scrap = 0;
        foreach (object o in my_scrap) {
          if ( strsrch(file_name(o), STD_CRAFTING + "survival/scrap_" + material) != -1) {
  	    scrap = o;
          }
        }
        if (!scrap) {
          who->eventPrint("You need some " + material + " scrap to resize this!\n(See <help scrap>.)");
  	  return 0;
        }
        send_messages("start", "$agent_name $agent_verb working some " + scrap->GetShort() +
          " into " + junk->GetShort() + ".", who, 0, environment(who));
        // store mats into an array to destroy later.
        my_mats += ({ scrap });
        } else {
          send_messages("rip", "$agent_name $agent_verb some useless " + material + " from " +
		      junk->GetShort() + ".", who, 0, environment(who));
        }
        who->AddStaminaPoints(-50);
        if (who->GetStaminaPoints() < 50) {
          who->eventPrint("You're too tired to continue properly, and stop.");
	  return 0;
        }
      }
    }

    // actually resize the thing.
    junk->SetSize(sizes[size]);

    if (my_mats) {
      foreach(scrap in my_mats) {
        scrap->eventDestruct();
    }
  }

  send_messages("resize", "$agent_name $agent_verb $target_name to " +
		size + " size.", who, junk, environment(who));
  return 1;
}

